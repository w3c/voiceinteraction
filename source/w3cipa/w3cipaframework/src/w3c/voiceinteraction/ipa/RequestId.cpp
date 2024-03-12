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

#include "w3c/voiceinteraction/ipa/RequestId.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

RequestId::RequestId() {
}

RequestId::~RequestId() {
}

bool RequestId::operator<(const RequestId& other) const {
    return toString() < other.toString();
}

bool RequestId::operator==(const RequestId& other) const {
    return toString() == other.toString();
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
