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

#include "w3c/voiceinteraction/ipa/client/ModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

ModalityComponent::ModalityComponent(const ModalityType& modality)
    : modality(modality) {
}

/**
 * Destroys the object.
 */
ModalityComponent::~ModalityComponent() {
}

/**
 * Retrieves a string identifying the modality of this input.
 */
const ModalityType& ModalityComponent::getModality() const {
    return modality;
}

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
