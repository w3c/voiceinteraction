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

#if !defined(MODALITYMANAGER_H)
#define MODALITYMANAGER_H

#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

#include "w3c/voiceinteraction/ipa/MultiModalOutputs.h"
#include "ModalityComponent.h"
#include "InputModalityComponent.h"
#include "InputModalityComponentListener.h"
#include "OutputModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

/**
 * A component that manages multiple modalities.
 * @author Dirk Schnelle-Walka
 */
class ModalityManager
{

public:
    /**
     * Constructs a new object.
     */
    ModalityManager() {
    }

    /**
     * Destroys the object.
     */
    virtual ~ModalityManager() {
    }

    /**
     * Adds a modality component to the set of modality components.
     * @param component The modality component to add to the set of modality
     * 			components.
     * @throws std::invalid_argument if the type is not supported
     */
    void addModalityComponent(
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

    /**
     * Gets the modality components for the specified modality and IO type.
     * @param modality The modality for which to get the modality component.
     * @param ioType The IOType for which to get the modality component.
     * @return The known modality components for the specified modality and
     *          type. An empty list is returned, if no modality was found.
     * @throws std::invalid_argument if the type is not supported
     */
    std::list<std::shared_ptr<ModalityComponent>> getModalityComponents(
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

    /**
     * Starts the input for all known modality handlers.
     * @param listener the listener for inputs.
     */
    void startInput(std::shared_ptr<InputModalityComponentListener>& listener) const {
        for (std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>>::const_iterator iterator =
            inputComponents.begin(); iterator != inputComponents.end();
             ++iterator) {
            std::list<std::shared_ptr<ModalityComponent>> components = iterator->second;
            for (std::shared_ptr<ModalityComponent> component : components) {
                std::shared_ptr<dialog::InputModalityComponent> inputComponent =
                    std::dynamic_pointer_cast<dialog::InputModalityComponent>(component);
                inputComponent->startInput(listener);
            }

        }
    }

    /**
     * Handles the provided multimodal output with all known modality handlers.
     * @param outputs the outputs to process
     */
    void handleOutput(const std::shared_ptr<MultiModalOutputs>& outputs) const {
        std::list<ModalityType> outputModalities = outputs->getModalityTypes();
        for (ModalityType outputModality : outputModalities) {
            std::shared_ptr<MultiModalOutput> output =
                outputs->getMultiModalOutput(outputModality);
            std::list<std::shared_ptr<dialog::ModalityComponent>> outputComponents =
                getModalityComponents(outputModality, dialog::IOType::OUTPUT);
            for (std::shared_ptr<dialog::ModalityComponent> outputComponent : outputComponents) {
                std::shared_ptr<dialog::OutputModalityComponent> outputModality =
                    std::dynamic_pointer_cast<dialog::OutputModalityComponent>(outputComponent);
                outputModality->handleOutput(output);
            }
        }
    }
private:
    /**
     * @brief Adds the provided modality component as an input modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addInputModality(const ModalityType& modality,
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

    /**
     * @brief Adds the provided modality component as an output modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addOutputModality(const ModalityType& modality,
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

    /**
     * The map of known input modality components.
     */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> inputComponents;
    /**
     * The map of known output modality components.
     */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> outputComponents;
};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MODALITYMANAGER_H)
