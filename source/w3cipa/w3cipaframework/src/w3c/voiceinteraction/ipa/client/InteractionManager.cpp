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
    const std::list<InteractionType>& types = component->getSupportedInteractionTypes();
    for (InteractionType type : types) {
        switch (type) {
        case InteractionType::CAPTURE:
            addCaptureModality(modality, component);
            break;
        case InteractionType::PRESENTATION:
            addPresentationModality(modality, component);
            break;
        default:
            std::stringstream ss;
            ss << "Unsupported interaction type " << type;
            std::string error = ss.str();
            throw new std::invalid_argument(error.c_str());
        }
    }
}

std::list<std::shared_ptr<ModalityComponent>> InteractionManager::getModalityComponents(
        const ModalityType& modality, const InteractionType& ioType) const {
    if (ioType == InteractionType::CAPTURE) {
        std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
            captureComponents.find(modality);
        if (iterator == captureComponents.end()) {
            return std::list<std::shared_ptr<ModalityComponent>>();
        }
        return iterator->second;
    } else if (ioType == InteractionType::PRESENTATION){
        std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
            presentationComponents.find(modality);
        if (iterator == presentationComponents.end()) {
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

void InteractionManager::startCapture() const {
    for (std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
        captureComponents.begin(); iterator != captureComponents.end();
         ++iterator) {
        std::list<std::shared_ptr<ModalityComponent>> components = iterator->second;
        for (std::shared_ptr<ModalityComponent>& component : components) {
            std::shared_ptr<client::CaptureModalityComponent> inputComponent =
                std::dynamic_pointer_cast<client::CaptureModalityComponent>(component);
            inputComponent->startCapture(inputNotifcation);
        }

    }
}

void InteractionManager::processIPAData(std::shared_ptr<IPAData> data) {
    if (std::shared_ptr<IPAResponse> response =
            std::dynamic_pointer_cast<IPAResponse>(data)) {
        std::shared_ptr<MultiModalDataCollection> outputs =
            response->getMultiModalOutputs();
        present(outputs);
    }
}

void InteractionManager::present(
        const std::shared_ptr<MultiModalDataCollection>& outputs) const {
    // Obtain all output modalities for the current type
    std::list<ModalityType> outputModalities = outputs->getModalityTypes();

    // Forwards the output to all output modality components of the current type
    for (ModalityType& outputModality : outputModalities) {
        std::shared_ptr<MultiModalData> output =
            outputs->getMultiModalData(outputModality);
        std::list<std::shared_ptr<client::ModalityComponent>> outputComponents =
            getModalityComponents(outputModality, client::InteractionType::PRESENTATION);
        for (std::shared_ptr<client::ModalityComponent>& outputComponent : outputComponents) {
            std::shared_ptr<client::PresentationModalityComponent> outputModality =
                std::dynamic_pointer_cast<client::PresentationModalityComponent>(outputComponent);
            outputModality->present(output);
        }
    }
}

void InteractionManager::addInputModalityComponentListener(
        const std::shared_ptr<CaptureModalityComponentListener>& listener) {
    inputNotifcation->addInputModalityComponentListener(listener);
}

void InteractionManager::operator>>(
        const std::shared_ptr<CaptureModalityComponentListener>& listener) {
    addInputModalityComponentListener(listener);
}

void InteractionManager::addCaptureModality(const ModalityType& modality,
                      const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::iterator iterator =
        captureComponents.find(modality);
    if (iterator == captureComponents.end()) {
        std::list<std::shared_ptr<ModalityComponent>> emptyList;
        captureComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<ModalityComponent>>& components =
        captureComponents.at(modality);
    components.push_back(component);
}

void InteractionManager::addPresentationModality(const ModalityType& modality,
                       const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::iterator iterator =
        presentationComponents.find(modality);
    if (iterator == presentationComponents.end()) {
        std::list<std::shared_ptr<ModalityComponent>> emptyList;
        presentationComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<ModalityComponent>>& components =
        presentationComponents.at(modality);
    components.push_back(component);
}

void InteractionManager::stopCapturing() const {
  for (std::map<ModalityType,
                std::list<std::shared_ptr<ModalityComponent>>>::const_iterator
           iterator = captureComponents.begin();
       iterator != captureComponents.end(); ++iterator) {
    std::list<std::shared_ptr<ModalityComponent>> components = iterator->second;
    for (std::shared_ptr<ModalityComponent>& component : components) {
      std::shared_ptr<client::CaptureModalityComponent> inputComponent =
          std::dynamic_pointer_cast<client::CaptureModalityComponent>(
              component);
      inputComponent->stopCapture();
    }
  }
}

std::shared_ptr<IPADataProcessor> operator >>(
        const std::shared_ptr<InteractionManager>& manager,
        const std::shared_ptr<CaptureModalityComponentListener>& listener) {
    manager->addInputModalityComponentListener(listener);
    return std::dynamic_pointer_cast<IPADataProcessor>(listener);
}

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
