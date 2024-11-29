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

#include "w3c/voiceinteraction/ipa/ExternalIPAResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

ExternalIPAResponse::ExternalIPAResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
               const std::shared_ptr<RequestId>& requestIdentifier,
               const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
               const std::shared_ptr<SemanticInterpretation> semanticInterpretation)
    : IPAData(sessionIdentifier, requestIdentifier),
    outputs(multiModalOutputs), interpretation(semanticInterpretation),
    error(nullptr) {
}

ExternalIPAResponse::ExternalIPAResponse(
                const std::shared_ptr<SessionId>& sessionIdentifier,
                const std::shared_ptr<RequestId>& requestIdentifier,
                const std::shared_ptr<ErrorMessage>& errorMessage)
    : IPAData(sessionIdentifier, requestIdentifier),
    outputs(nullptr), interpretation(nullptr),
    error(errorMessage) {
}

ExternalIPAResponse::~ExternalIPAResponse() {
}

const std::shared_ptr<MultiModalOutputs> ExternalIPAResponse::getMultiModalOutputs() const {
    return outputs;
}

const std::shared_ptr<SemanticInterpretation> ExternalIPAResponse::getSemanticInterpretation() const {
    return interpretation;
}

CallResult ExternalIPAResponse::getCallResult() const {
    if (error == nullptr) {
        return CallResult::SUCCESS;
    } else {
        return CallResult::FAILURE;
    }
}

bool ExternalIPAResponse::hasError() const {
    return error != nullptr;
}

const std::shared_ptr<ErrorMessage> ExternalIPAResponse:: getErrorMessage() const {
    return error;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
