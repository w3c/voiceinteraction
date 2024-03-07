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

#ifndef OUTPUTMODALITYCOMPONENT_H
#define OUTPUTMODALITYCOMPONENT_H

#include <memory>

#include "w3c/voiceinteraction/ipa/MultiModalOutput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A compponent to hand mutlimodal outputs.
 *
 * Output modality components are also asked to inherit from
 * {@link ModalityComponent} and support {@link IOType::OUTPUT}.
 *
 * @author Dirk Schnelle-Walka
 */
class OutputModalityComponent {
public:
    /**
     * Creates a object.
     */
    OutputModalityComponent() {
    }

    /**
     * @brief Destroys this object
     */
    virtual ~OutputModalityComponent() {
    }
    /**
     * Handles the obtained mutlitmodal output.
     * @param output the obtained output.
     */
    virtual void handleOutput(
            const std::shared_ptr<MultiModalOutput>& output) = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // OUTPUTMODALITYCOMPONENT_H
