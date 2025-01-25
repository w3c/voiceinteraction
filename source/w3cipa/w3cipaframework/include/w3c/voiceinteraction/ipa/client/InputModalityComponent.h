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

#ifndef INPUTMODALITYCOMPONENT_H
#define INPUTMODALITYCOMPONENT_H

#include <memory>

#include "w3c/voiceinteraction/ipa/client/InputNotificationMediator.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief A component to handle multimodal inputs.
 *
 * Input modality components are also required to inherit from
 * {@link ModalityComponent} and support {@link IOType#INPUT}.
 * 
 * This class provides an interface for starting and stopping the listening
 * for inputs and notifying a mediator when inputs are received.
 * 
 * @note This is an abstract class and should be inherited by specific input
 * modality implementations.
 * 
 * @see ModalityComponent
 * @see IOType
 * @see InputNotificationMediator
 * 
 * @author Dirk Schnelle-Walka
 */
class InputModalityComponent {
public:
    /**
     * @brief Constructs an InputModalityComponent object.
     */
    InputModalityComponent();

    /**
     * @brief Destroys the InputModalityComponent object.
     */
    virtual ~InputModalityComponent();

    /**
     * @brief Starts listening asynchronously for inputs and notifies the provided
     * mediator if any input is received from this component.
     * 
     * @param mediator The mediator to handle input notifications.
     */
    virtual void startInput(
        const std::shared_ptr<InputNotificationMediator>& mediator) = 0;

    /**
     * @brief Stops listening for inputs.
     */
    virtual void stopInput() = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // INPUTMODALITYCOMPONENT_H
