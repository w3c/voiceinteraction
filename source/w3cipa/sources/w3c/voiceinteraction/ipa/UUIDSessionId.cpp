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

#include "UUIDSessionId.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

UUIDSessionId::UUIDSessionId() {
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};

    id = gen();
}

UUIDSessionId::UUIDSessionId(const UUIDSessionId& sessionId)
    : id(sessionId.id) {
}

void UUIDSessionId::operator=(const UUIDSessionId& other) {
    id = other.id;
}

const std::string UUIDSessionId::toString() const {
    return uuids::to_string(id);
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
