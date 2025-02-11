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

#ifndef INPUTNOTIFICATIONMEDIATOR_H
#define INPUTNOTIFICATIONMEDIATOR_H

#include <list>
#include <memory>

#include "CaptureModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief A mediator for managing listeners of multimodal input events.
 * 
 * This class maintains a list of listeners that are notified when new
 * multimodal inputs are received. It provides methods to add listeners
 * and to notify all registered listeners of new inputs.
 * 
 * @note This class is part of the IPA Reference Implementation.
 * 
 * @see InputModalityComponentListener
 * @see MultiModalData
 * 
 * @author Dirk Schnelle-Walka
 */
class InputNotificationMediator : public CaptureModalityComponentListener {
public:
    /**
     * @brief Constructs a new InputNotificationMediator object.
     */
    InputNotificationMediator();

    /**
     * @brief Destroys the InputNotificationMediator object.
     */
    ~InputNotificationMediator();

    /**
     * @brief Adds a listener for multimodal inputs.
     * 
     * This method adds the provided listener to the list of known listeners
     * that will be notified of new multimodal inputs.
     * 
     * @param listener The listener to add.
     */
    void addInputModalityComponentListener(
            const std::shared_ptr<CaptureModalityComponentListener>& listener);

    /**
     * {@inheritDoc} 
     */
    virtual void onMultiModalInput(std::shared_ptr<MultiModalData> input) override;

    /**
     * {@inheritDoc}
     * @ return Always {@code nullptr}.
     */
    virtual std::shared_ptr<MultiModalDataCollection> getMultiModalInputs() override;

private:
    /**
     * @brief Notifies all registered listeners of a new multimodal input.
     * 
     * This method notifies all listeners that have been added via the
     * addInputModalityComponentListener method about the received multimodal input.
     * 
     * @param input The multimodal input to notify listeners about.
     */
    void notifyListeners(std::shared_ptr<MultiModalData> input);

    /** List of registered listeners for multimodal inputs. */
    std::list<std::shared_ptr<CaptureModalityComponentListener>> inputListeners;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // INPUTNOTIFICATIONMEDIATOR_H
