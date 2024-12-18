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

#include "w3c/voiceinteraction/ipa/MultiModalDataCollection.h"
#include "w3c/voiceinteraction/ipa/IPADataProcessor.h"
#include "ModalityComponent.h"
#include "InputModalityComponent.h"
#include "InputModalityComponentListener.h"
#include "InputNotificationMediator.h"
#include "OutputModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A component that manages multiple modalities.
 * @author Dirk Schnelle-Walka
 */
class ModalityManager : public IPADataProcessor {

public:
    /**
     * Constructs a new object.
     */
    ModalityManager();

    /**
     * Destroys the object.
     */
    virtual ~ModalityManager();

    /**
     * Adds a modality component to the set of modality components.
     * @param component The modality component to add to the set of modality
     * 			components.
     * @throws std::invalid_argument if the type is not supported
     */
    void addModalityComponent(
        const std::shared_ptr<ModalityComponent> component);

    /**
     * Gets the modality components for the specified modality and IO type.
     * @param modality The modality for which to get the modality component.
     * @param ioType The IOType for which to get the modality component.
     * @return The known modality components for the specified modality and
     *          type. An empty list is returned, if no modality was found.
     * @throws std::invalid_argument if the type is not supported
     */
    std::list<std::shared_ptr<ModalityComponent>> getModalityComponents(
        const ModalityType& modality, const IOType& ioType) const;

    /**
     * Starts the input for all known modality handlers.
     */
    void startInput() const;

    void processIPAData(std::shared_ptr<IPAData> data) override;

    /**
     * Handles the provided multimodal output with all known modality handlers.
     * @param outputs the outputs to process
     */
    void handleOutput(const std::shared_ptr<MultiModalDataCollection>& outputs) const;

    /**
     * Adds the provided listener for multimodal inputs to the list of known
     * listeners.
     * @param listener the listener to add.
     */
    void addInputModalityComponentListener(
            const std::shared_ptr<InputModalityComponentListener>& listener);

    /**
     * Adds the provided listener for multimodal inputs to the list of known
     * listeners.
     * @param listener the listener to add.
     */
    void operator >>(
            const std::shared_ptr<InputModalityComponentListener>& listener);
private:
    /**
     * @brief Adds the provided modality component as an input modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addInputModality(const ModalityType& modality,
                          const std::shared_ptr<ModalityComponent>& component);

    /**
     * @brief Adds the provided modality component as an output modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addOutputModality(const ModalityType& modality,
                           const std::shared_ptr<ModalityComponent>& component);

    /** The map of known input modality components. */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> inputComponents;

    /** The map of known output modality components. */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> outputComponents;

    /** Mediator to forward input events. */
    std::shared_ptr<InputNotificationMediator> inputNotifcation;
};

std::shared_ptr<IPADataProcessor> operator>>(
        const std::shared_ptr<ModalityManager>& manager,
        const std::shared_ptr<InputModalityComponentListener>& listener);

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MODALITYMANAGER_H)
