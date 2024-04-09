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

#include "w3c/voiceinteraction/ipa/CombinedId.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

CombinedId::CombinedId(const std::shared_ptr<SessionId> &session,
                       const std::shared_ptr<RequestId> &request)
    : sessionId(session), requestId(request) {
    combinedId = sessionId->toString();
    if (requestId != nullptr) {
        combinedId += "::" + requestId->toString();
    }
}

CombinedId::CombinedId(const CombinedId& other)
    : sessionId(other.sessionId), requestId(other.requestId),
      combinedId(other.combinedId) {
}

CombinedId::~CombinedId() {
}

const std::shared_ptr<SessionId>& CombinedId::getSessionId() const {
    return sessionId;
}

const std::shared_ptr<RequestId>& CombinedId::getRequestId() const {
    return requestId;
}

const std::string& CombinedId::toString() const {
    return combinedId;
}

bool CombinedId::operator<(const CombinedId& other) const {
    return combinedId < other.combinedId;
}

bool CombinedId::operator==(const CombinedId& other) const {
    return combinedId == other.combinedId;
}

CombinedId& CombinedId::operator=(const CombinedId& other) {
    sessionId = other.sessionId;
    requestId = other.requestId;
    combinedId = other.combinedId;
    return *this;
}


} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
