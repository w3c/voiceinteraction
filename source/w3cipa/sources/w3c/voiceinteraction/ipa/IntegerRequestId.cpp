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

#include <sstream>
#include <iomanip>
#include <atomic>

#include "IntegerRequestId.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

IntegerRequestId::IntegerRequestId() {
    id = nextId();
    std::ostringstream out;
    out << std::setw(10) << std::setfill('0') << id;
    idString = out.str();
}

const std::string& IntegerRequestId::toString() const {
    return idString;
}

long IntegerRequestId::nextId() {
    static std::atomic<long> counter{ 0 };
    return ++counter;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
