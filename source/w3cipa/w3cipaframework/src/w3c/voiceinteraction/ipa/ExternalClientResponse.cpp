﻿/*
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

#include "w3c/voiceinteraction/ipa/ExternalClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

ExternalClientResponse::ExternalClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
               const std::shared_ptr<RequestId>& requestIdentifier,
               const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
               const std::shared_ptr<SemanticInterpretation> semanticInterpretation)
    : sessionId(sessionIdentifier), requestId(requestIdentifier),
    outputs(multiModalOutputs), interpretation(semanticInterpretation),
    error(nullptr) {
}

ExternalClientResponse::ExternalClientResponse(
                const std::shared_ptr<SessionId>& sessionIdentifier,
                const std::shared_ptr<RequestId>& requestIdentifier,
                const std::shared_ptr<ErrorMessage>& errorMessage)
    : sessionId(sessionIdentifier), requestId(requestIdentifier),
    outputs(nullptr), interpretation(nullptr),
    error(errorMessage) {
}

ExternalClientResponse::~ExternalClientResponse() {
}

const std::shared_ptr<SessionId> ExternalClientResponse::getSessionId() const {
    return sessionId;
}

const std::shared_ptr<RequestId>& ExternalClientResponse::getRequestId() const {
    return requestId;
}

const std::shared_ptr<MultiModalOutputs> ExternalClientResponse::getMultiModalOutputs() const {
    return outputs;
}

const std::shared_ptr<SemanticInterpretation> ExternalClientResponse::getSemanticInterpretation() const {
    return interpretation;
}

bool ExternalClientResponse::hasError() const {
    return error != nullptr;
}

const std::shared_ptr<ErrorMessage> ExternalClientResponse:: getErrorMessage() const {
    return error;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
