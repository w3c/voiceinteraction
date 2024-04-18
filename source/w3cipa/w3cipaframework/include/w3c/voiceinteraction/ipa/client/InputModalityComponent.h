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

#include "w3c/voiceinteraction/ipa/client/InputModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A component to hand mutlimodal inputs.
 *
 * Input modality components are also asked to inherit from
 * {@link ModalityComponent} and support {@link IOType::INPUT}.
 * @author Dirk Schnelle-Walka
 */
class InputModalityComponent {
public:
    /**
     * Creates a object.
     */
    InputModalityComponent();

    /**
     * @brief Destroy this object.
     */
    virtual ~InputModalityComponent();

    /**
     * Starts listening asynchronously for inputs and notify the provided
     * listener if any input is received from this component.
     * @param listener the lister to notify
     */
    virtual void startInput(
        std::shared_ptr<InputModalityComponentListener> listener) = 0;

    /**
     * Stops listening for inputs.
     */
    virtual void stopInput() = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // INPUTMODALITYCOMPONENT_H
