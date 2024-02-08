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

#include "ModalityComponent.h"
#include "../MultiModalOutput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

/**
 * A compponent to hand mutlimodal outputs.
 * @author Dirk Schnelle-Walka
 */
class OutputModalityComponent : public ModalityComponent {
public:
    /**
     * Creates a object.
     * @param modality the supported modality.
     */
     OutputModalityComponent(const ModalityType& modality)
        : ModalityComponent(modality) {
    }

    /**
     * Retrieves the IO type of this modality component.
     * @return {@link IOType#OUTPUT}
     */
    virtual const IOType getIOType() const {
         return IOType::OUTPUT;
    }

    /**
     * Handles the obtained mutlitmodal output.
     * @param output the obtained output.
     */
    virtual void handleOutput(
            const std::shared_ptr<MultiModalOutput> output) = 0;
};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // OUTPUTMODALITYCOMPONENT_H
