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

#include "w3c/voiceinteraction/ipa/ExternalClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

ExternalClientResponse::ExternalClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
               const std::shared_ptr<RequestId>& requestIdentifier,
               const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
               const std::shared_ptr<SemanticInterpretation> semanticInterpretation)
    : IPAData(sessionIdentifier, requestIdentifier),
    outputs(multiModalOutputs), interpretation(semanticInterpretation),
    error(nullptr) {
}

ExternalClientResponse::ExternalClientResponse(
                const std::shared_ptr<SessionId>& sessionIdentifier,
                const std::shared_ptr<RequestId>& requestIdentifier,
                const std::shared_ptr<ErrorMessage>& errorMessage)
    : IPAData(sessionIdentifier, requestIdentifier),
    outputs(nullptr), interpretation(nullptr),
    error(errorMessage) {
}

ExternalClientResponse::~ExternalClientResponse() {
}

const std::shared_ptr<MultiModalOutputs> ExternalClientResponse::getMultiModalOutputs() const {
    return outputs;
}

const std::shared_ptr<SemanticInterpretation> ExternalClientResponse::getSemanticInterpretation() const {
    return interpretation;
}

CallResult ExternalClientResponse::getCallResult() const {
    if (error == nullptr) {
        return CallResult::SUCCESS;
    } else {
        return CallResult::FAILURE;
    }
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
