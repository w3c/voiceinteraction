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

#include "w3c/voiceinteraction/ipa/IPAData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

IPAData::IPAData(const std::shared_ptr<SessionId>& sessionIdentifier,
        const std::shared_ptr<RequestId>& requestIdentifier)
    : sessionId(sessionIdentifier), requestId(requestIdentifier) {
}

IPAData::IPAData(const std::shared_ptr<SessionId>& sessionIdentifier)
    : sessionId(sessionIdentifier), requestId (nullptr) {
}

IPAData::~IPAData() {
}

const std::shared_ptr<SessionId>& IPAData::getSessionId() const {
    return sessionId;
}

void IPAData::setSessionId(const std::shared_ptr<SessionId>& sessionIdentifier) {
    sessionId = sessionIdentifier;
}

const std::shared_ptr<RequestId>& IPAData::getRequestId() const {
    return requestId;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
