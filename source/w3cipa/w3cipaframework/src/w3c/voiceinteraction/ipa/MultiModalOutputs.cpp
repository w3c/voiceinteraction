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

#include "w3c/voiceinteraction/ipa/MultiModalOutputs.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

MultiModalOutputs::MultiModalOutputs() {
}

MultiModalOutputs::~MultiModalOutputs() {
}

void MultiModalOutputs::addMultiModalOutput(
    const std::shared_ptr<MultiModalOutput>& output) {
    const ModalityType& modality = output->getModality();
    outputs[modality] = output;
}

std::shared_ptr<MultiModalOutput> MultiModalOutputs::getMultiModalOutput(
    const ModalityType& modality) {
    return outputs[modality];
}

std::list<ModalityType> MultiModalOutputs::getModalityTypes() const {
    std::list<ModalityType> types;
    for (std::map<ModalityType, std::shared_ptr<MultiModalOutput>>::const_iterator iterator = outputs.begin();
         iterator != outputs.end(); ++iterator) {
        const ModalityType type = iterator->first;
        types.push_back(type);
    }
    return types;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
