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

#include "w3c/voiceinteraction/ipa/IPARequest.h"
#include "w3c/voiceinteraction/ipa/IPAResponse.h"
#include "w3c/voiceinteraction/ipa/client/InteractionManager.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

InteractionManager::InteractionManager() 
    : shouldExit(false) {
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

std::list<std::shared_ptr<CaptureModalityComponent>> InteractionManager::getCaptureModalityComponents(
        const ModalityType& modality) const {
  std::map<ModalityType,
           std::list<std::shared_ptr<CaptureModalityComponent>>>::const_iterator
      iterator = captureComponents.find(modality);
  if (iterator == captureComponents.end()) {
    return std::list<std::shared_ptr<CaptureModalityComponent>>();
  }
  return iterator->second;
}

std::list<std::shared_ptr<PresentationModalityComponent>> InteractionManager::getPresentationModalityComponents(const ModalityType& modality) const {
    std::map<ModalityType,
           std::list<std::shared_ptr<PresentationModalityComponent>>>::
      const_iterator
        iterator = presentationComponents.find(modality);
    if (iterator == presentationComponents.end()) {
      return std::list<std::shared_ptr<PresentationModalityComponent>>();
    }
    return iterator->second;
}

void InteractionManager::start() {
  startCapture();
}

void InteractionManager::waitExit() {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [this] { return shouldExit; });
}

void InteractionManager::startCapture() const {
    for (std::map<ModalityType, std::list<std::shared_ptr<CaptureModalityComponent>>>::const_iterator iterator =
        captureComponents.begin(); iterator != captureComponents.end();
         ++iterator) {
    std::list<std::shared_ptr<CaptureModalityComponent>> components =
        iterator->second;
      for (std::shared_ptr<CaptureModalityComponent>& component : components) {
            component->startCapture(synchronisationStrategy);
        }
    }
}

void InteractionManager::stopCapture() const {
  for (std::map<ModalityType,
                std::list<std::shared_ptr<CaptureModalityComponent>>>::
           const_iterator
           iterator = captureComponents.begin();
       iterator != captureComponents.end(); ++iterator) {
    std::list<std::shared_ptr<CaptureModalityComponent>> components =
        iterator->second;
    for (std::shared_ptr<CaptureModalityComponent>& component : components) {
      component->stopCapture();
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
        const std::shared_ptr<MultiModalDataCollection>& outputs) {
    // Obtain all output modalities for the current type
    std::list<ModalityType> outputModalities = outputs->getModalityTypes();

    // Forwards the output to all output modality components of the current type
    for (ModalityType& outputModality : outputModalities) {
      std::shared_ptr<MultiModalData> output =
          outputs->getMultiModalData(outputModality);
      std::list<std::shared_ptr<PresentationModalityComponent>> outputComponents =
          getPresentationModalityComponents(outputModality);
      for (std::shared_ptr<client::PresentationModalityComponent>&
               outputComponent :
           outputComponents) {
        outputComponent->present(output);
      }
    }

  std::unique_lock<std::mutex> lock(mtx);
  shouldExit = true;
  cv.notify_all();
}

void InteractionManager::onMultimodalInput(
    std::shared_ptr<MultiModalDataCollection>& data) {
  // Stop capturing input
  stopCapture();

  // Forward the request to the next element in the processing chain
  // TODO add the RequestID and SessionID
  std::shared_ptr<IPARequest> request =
      std::make_shared<IPARequest>(nullptr, nullptr, data, nullptr, nullptr);
  notifyListeners(request);
}

void InteractionManager::setMultimodalCaptureSynchronizationStrategy(
        const std::shared_ptr<CaptureModalityComponentListener>& listener) {
    synchronisationStrategy = listener;
}

void InteractionManager::addCaptureModality(const ModalityType& modality,
                      const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<CaptureModalityComponent>>>::iterator iterator =
        captureComponents.find(modality);
    if (iterator == captureComponents.end()) {
      std::list<std::shared_ptr<CaptureModalityComponent>> emptyList;
        captureComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<CaptureModalityComponent>>& components =
        captureComponents.at(modality);
    std::shared_ptr<CaptureModalityComponent> captureComponent =
        std::dynamic_pointer_cast<CaptureModalityComponent>(component);
    components.push_back(captureComponent);
}

void InteractionManager::addPresentationModality(const ModalityType& modality,
                       const std::shared_ptr<ModalityComponent>& component) {
    std::map<ModalityType, std::list<std::shared_ptr<PresentationModalityComponent>>>::iterator iterator =
        presentationComponents.find(modality);
    if (iterator == presentationComponents.end()) {
      std::list<std::shared_ptr<PresentationModalityComponent>> emptyList;
        presentationComponents[modality] = emptyList;
    }
    std::list<std::shared_ptr<PresentationModalityComponent>>& components =
        presentationComponents.at(modality);
    std::shared_ptr<PresentationModalityComponent> presentationComponent =
        std::dynamic_pointer_cast<PresentationModalityComponent>(component);
    components.push_back(presentationComponent);
}

const std::shared_ptr<InteractionManager>& operator>>(
    const std::shared_ptr<ModalityComponent>& mc,
    const std::shared_ptr<InteractionManager>& im) {
  im->addModalityComponent(mc);
  return im;
}

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
