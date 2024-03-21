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

#include "w3c/voiceinteraction/ipa/client/ModalityManager.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

ModalityManager::ModalityManager() {
}

ModalityManager::~ModalityManager() {
}

void ModalityManager::addModalityComponent(
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

std::list<std::shared_ptr<ModalityComponent>> ModalityManager::getModalityComponents(
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

void ModalityManager::startInput(std::shared_ptr<InputModalityComponentListener>& listener) const {
    for (std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
        inputComponents.begin(); iterator != inputComponents.end();
         ++iterator) {
        std::list<std::shared_ptr<ModalityComponent>> components = iterator->second;
        for (std::shared_ptr<ModalityComponent> component : components) {
            std::shared_ptr<client::InputModalityComponent> inputComponent =
                std::dynamic_pointer_cast<client::InputModalityComponent>(component);
            inputComponent->startInput(listener);
        }

    }
}

void ModalityManager::handleOutput(const std::shared_ptr<MultiModalOutputs>& outputs) const {
    std::list<ModalityType> outputModalities = outputs->getModalityTypes();
    for (ModalityType outputModality : outputModalities) {
        std::shared_ptr<MultiModalOutput> output =
            outputs->getMultiModalOutput(outputModality);
        std::list<std::shared_ptr<client::ModalityComponent>> outputComponents =
            getModalityComponents(outputModality, client::IOType::OUTPUT);
        for (std::shared_ptr<client::ModalityComponent> outputComponent : outputComponents) {
            std::shared_ptr<client::OutputModalityComponent> outputModality =
                std::dynamic_pointer_cast<client::OutputModalityComponent>(outputComponent);
            outputModality->handleOutput(output);
        }
    }
}

void ModalityManager::addInputModality(const ModalityType& modality,
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

void ModalityManager::addOutputModality(const ModalityType& modality,
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

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
