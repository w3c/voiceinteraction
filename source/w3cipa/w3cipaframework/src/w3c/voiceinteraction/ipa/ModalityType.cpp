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


#include "w3c/voiceinteraction/ipa/ModalityType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

ModalityType::ModalityType(const std::string& modalityType)
    : modalityType(modalityType) {
}

ModalityType::ModalityType(const ModalityType& other)
    : modalityType(other.getModalityType()) {
}

ModalityType::~ModalityType() {
}

const std::string& ModalityType::getModalityType() const {
    return modalityType;
}

bool ModalityType::operator<(const ModalityType& other) const {
    return modalityType < other.getModalityType();
}

void ModalityType::operator=(const ModalityType& other) {
    modalityType = other.getModalityType();
}

bool ModalityType::operator==(const ModalityType& other) const {
    return modalityType == other.getModalityType();
}


} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

