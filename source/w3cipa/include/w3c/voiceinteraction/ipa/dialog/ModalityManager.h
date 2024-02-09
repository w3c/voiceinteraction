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

#include "ModalityComponent.h"

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
     *          type.
     */
    std::list<std::shared_ptr<ModalityComponent>> getModalityComponents(
            const ModalityType& modality, const IOType& ioType) {
        if (ioType == IOType::INPUT) {
            return inputComponents[modality];
        } else {
            return outputComponents[modality];
        }
    }
private:
    /**
     * @brief Adds the provided modality component as an input modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addInputModality(const ModalityType& modality,
                          const std::shared_ptr<ModalityComponent> component) {
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
                           const std::shared_ptr<ModalityComponent> component) {
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
