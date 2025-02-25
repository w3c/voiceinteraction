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

#ifndef CAPTURE_MODALITYCOMPONENT_H
#define CAPTURE_MODALITYCOMPONENT_H

#include <memory>

#include "w3c/voiceinteraction/ipa/client/CaptureModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief A component to capture multimodal inputs.
 *
 * Capture modality components are also required to inherit from
 * {@link ModalityComponent} and support {@link InteractionType#CAPTURE}.
 * 
 * This class provides an interface for starting and stopping the listening
 * for inputs and notifying a mediator when inputs are received.
 * 
 * @note This is an abstract class and should be inherited by specific input
 * modality implementations.
 * 
 * @see ModalityComponent
 * @see InteractionType
 * @see MulitModalCaptureSynchronisationStrategy
 * 
 * @author Dirk Schnelle-Walka
 */
class CaptureModalityComponent {
public:
    /**
     * @brief Constructs an InputModalityComponent object.
     */
    CaptureModalityComponent();

    /**
     * @brief Destroys the InputModalityComponent object.
     */
    virtual ~CaptureModalityComponent();

    /**
     * @brief Starts capturing asynchronously for inputs and notifies the provided
     * listner if any input is received from this component.
     * 
     * @param listener The listener to handle input notifications.
     */
    virtual void startCapture(
        const std::shared_ptr<CaptureModalityComponentListener>& listener) = 0;

    /**
     * @brief Stops listening for inputs.
     */
    virtual void stopCapture() = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // CAPTURE_MODALITYCOMPONENT_H
