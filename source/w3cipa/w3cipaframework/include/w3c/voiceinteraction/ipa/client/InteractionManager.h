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

#if !defined(INTERACTION_MANAGER_H)
#define INTERACTION_MANAGER_H

#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

#include "w3c/voiceinteraction/ipa/MultiModalDataCollection.h"
#include "w3c/voiceinteraction/ipa/IPADataProcessor.h"
#include "ModalityComponent.h"
#include "CaptureModalityComponent.h"
#include "CaptureModalityComponentListener.h"
#include "InputNotificationMediator.h"
#include "PresentationModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief A component that manages multiple modalities.
 *
 * The InteractionManager class is responsible for managing multiple modality
 * components, handling input and output modalities, and processing IPA data. It
 * provides methods to add modality components, retrieve modality components
 * based on modality type and IO type, start input for all known modality
 * handlers, process IPA data, handle multimodal output, and manage listeners
 * for multimodal inputs.
 *
 * @note This class is part of the IPA Reference Implementation.
 *
 * @see ModalityComponent
 * @see InputModalityComponentListener
 * @see InputNotificationMediator
 * @see MultiModalDataCollection
 * @see IPADataProcessor
 *
 * @author Dirk Schnelle-Walka
 */
class InteractionManager : public IPADataProcessor {
 public:
    /**
     * Constructs a new object.
     */
    InteractionManager();

    /**
     * Destroys the object.
     */
    virtual ~InteractionManager();

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
        const ModalityType& modality, const InteractionType& ioType) const;

    /**
     * Starts capturing input for all known modality handlers.
     */
    void startCapture() const;

    /**
     * {@inheritDoc}
     */
    void processIPAData(std::shared_ptr<IPAData> data) override;

    /**
     * Handles the provided multimodal output with all known modality handlers.
     * @param outputs the outputs to process
     */
    void present(const std::shared_ptr<MultiModalDataCollection>& outputs) const;

    /**
     * Adds the provided listener for multimodal inputs to the list of known
     * listeners.
     * @param listener the listener to add.
     */
    void addInputModalityComponentListener(
            const std::shared_ptr<CaptureModalityComponentListener>& listener);

    /**
     * Adds the provided listener for multimodal inputs to the list of known
     * listeners.
     * @param listener the listener to add.
     */
    void operator >>(
            const std::shared_ptr<CaptureModalityComponentListener>& listener);
private:
    /**
     * @brief Adds the provided modality component as an input modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addCaptureModality(const ModalityType& modality,
                          const std::shared_ptr<ModalityComponent>& component);

    /**
     * @brief Adds the provided modality component as an output modality
     * @param modality The modality for which to get the modality component.
     * @param component the component to add
     */
    void addPresentationModality(const ModalityType& modality,
                           const std::shared_ptr<ModalityComponent>& component);

    /**
     * @brief Stops capturing for all known modality components.
     */
    void stopCapturing() const;

    /** The map of known capture modality components. */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> captureComponents;

    /** The map of known presentation modality components. */
    std::map<ModalityType, std::list<std::shared_ptr<ModalityComponent>>> presentationComponents;

    /** Mediator to forward input events. */
    std::shared_ptr<InputNotificationMediator> inputNotifcation;
};

std::shared_ptr<IPADataProcessor> operator>>(
        const std::shared_ptr<InteractionManager>& manager,
        const std::shared_ptr<CaptureModalityComponentListener>& listener);

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(INTERACTION_MANAGER_H)
