/*
 * IPA Reference Implementation: https://github.com/w3c/voiceinteraction
 *
 * Copyright (C) 2024 World Wide Web Consortium. All Rights Reserved.
 *
 * This work is distributed under the W3C Software and Document License [1]
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] https://www.w3.org/Consortium/Legal/copyright-software
 */

#include "w3c/voiceinteraction/ipa/IPAResponse.h"
#include "w3c/voiceinteraction/ipa/client/InteractionManager.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

InteractionManager::InteractionManager()
    : inputNotifcation(std::make_shared<InputNotificationMediator>()) {
}

InteractionManager::~InteractionManager() {
}

void InteractionManager::addModalityComponent(
        const std::shared_ptr<ModalityComponent> component) {
    const ModalityType& modality = component->getModality();
    const std::list<IOType>& types = component->getSupportedIOTypes();
    for (IOType type : types) {
        switch (type) {
        case IOType::INPUT:
            addInputModality(modality, component);
            break;
        case IOType::OUTPUT:
            addOutputModality(modality, component);
            break;
        default:
            std::stringstream ss;
            ss << "Unsupported IO type " << type;
            std::string error = ss.str();
            throw new std::invalid_argument(error.c_str());
        }
    }
}

std::list<std::shared_ptr<ModalityComponent>> InteractionManager::getModalityComponents(
        const ModalityType& modality, const IOType& ioType) const {
    if (ioType == IOType::INPUT) {
        std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
            inputComponents.find(modality);
        if (iterator == inputComponents.end()) {
            return std::list<std::shared_ptr<ModalityComponent>>();
        }
        return iterator->second;
    } else if (ioType == IOType::OUTPUT){
        std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
            outputComponents.find(modality);
        if (iterator == outputComponents.end()) {
            return std::list<std::shared_ptr<ModalityComponent>>();
        }
        return iterator->second;
    } else {
        std::stringstream ss;
        ss << "Unsupported IO type " << ioType;
        std::string error = ss.str();
        throw new std::invalid_argument(error.c_str());
    }
}

void InteractionManager::startInput() const {
    for (std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
        inputComponents.begin(); iterator != inputComponents.end();
         ++iterator) {
        std::list<std::shared_ptr<ModalityComponent>> components = iterator->second;
        for (std::shared_ptr<ModalityComponent>& component : components) {
            std::shared_ptr<client::InputModalityComponent> inputComponent =
                std::dynamic_pointer_cast<client::InputModalityComponent>(component);
            inputComponent->startInput(inputNotifcation);
        }

    }
}

void InteractionManager::processIPAData(std::shared_ptr<IPAData> data) {
    if (std::shared_ptr<IPAResponse> response =
            std::dynamic_pointer_cast<IPAResponse>(data)) {
        std::shared_ptr<MultiModalDataCollection> outputs =
            response->getMultiModalOutputs();
        handleOutput(outputs);
    }
}

void InteractionManager::handleOutput(
        const std::shared_ptr<MultiModalDataCollection>& outputs) const {
    // Obtain all output modalities for the current type
    std::list<ModalityType> outputModalities = outputs->getModalityTypes();

    // Forwards the output to all output modality components of the current type
    for (ModalityType& outputModality : outputModalities) {
        std::shared_ptr<MultiModalData> output =
            outputs->getMultiModalData(outputModality);
        std::list<std::shared_ptr<client::ModalityComponent>> outputComponents =
            getModalityComponents(outputModality, client::IOType::OUTPUT);
        for (std::shared_ptr<client::ModalityComponent>& outputComponent : outputComponents) {
            std::shared_ptr<client::OutputModalityComponent> outputModality =
                std::dynamic_pointer_cast<client::OutputModalityComponent>(outputComponent);
            outputModality->handleOutput(output);
        }
    }
}

void InteractionManager::addInputModalityComponentListener(
        const std::shared_ptr<InputModalityComponentListener>& listener) {
    inputNotifcation->addInputModalityComponentListener(listener);
}

void InteractionManager::operator>>(
        const std::shared_ptr<InputModalityComponentListener>& listener) {
    addInputModalityComponentListener(listener);
}


void InteractionManager::addInputModality(const ModalityType& modality,
                      const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::iterator iterator =
        inputComponents.find(modality);
    if (iterator == inputComponents.end()) {
        std::list<std::shared_ptr<ModalityComponent>> emptyList;
        inputComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<ModalityComponent>>& components =
        inputComponents.at(modality);
    components.push_back(component);
}

void InteractionManager::addOutputModality(const ModalityType& modality,
                       const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::iterator iterator =
        outputComponents.find(modality);
    if (iterator == outputComponents.end()) {
        std::list<std::shared_ptr<ModalityComponent>> emptyList;
        outputComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<ModalityComponent>>& components =
        outputComponents.at(modality);
    components.push_back(component);
}

std::shared_ptr<IPADataProcessor> operator >>(
        const std::shared_ptr<InteractionManager>& manager,
        const std::shared_ptr<InputModalityComponentListener>& listener) {
    manager->addInputModalityComponentListener(listener);
    return std::dynamic_pointer_cast<IPADataProcessor>(listener);
}

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
