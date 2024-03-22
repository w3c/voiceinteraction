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

#include <log4cplus/loggingmacros.h>

#include "w3c/voiceinteraction/ipa/reference/UUIDSessionId.h"
#include "w3c/voiceinteraction/ipa/reference/TextMultiModalOutput.h"
#include "w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h"


namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace dialog {

const log4cplus::Logger ReferenceIPAService::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.dialog.ReferenceIPAService"));

ReferenceIPAService::ReferenceIPAService(
    const std::shared_ptr<ProviderSelectionService> &service)
    : IPAService(service) {
}

const std::shared_ptr<ClientResponse> ReferenceIPAService::processInput(
    const std::shared_ptr<ClientRequest> &request) {
    // Check if there is already a session identifer and set one if there is
    // none
    const std::shared_ptr<SessionId>& id = request->getSessionId();
    if (id == nullptr) {
        std::shared_ptr<SessionId> sessionIdentifier =
            std::make_shared<UUIDSessionId>();
        request->setSessionId(sessionIdentifier);
        LOG4CPLUS_INFO_FMT(LOGGER,
                           LOG4CPLUS_TEXT("Created new session identifier: %s"),
                           sessionIdentifier->toString().c_str());
    }
    std::list<std::shared_ptr<ExternalClientResponse>> responses =
        providerSelectionService->processInput(request);
    if (responses.size() == 0) {
        return nullptr;
    }

    // TODO For now, only return the first response
    const std::shared_ptr<ExternalClientResponse>& externalResponse =
        responses.front();
    std::shared_ptr<ClientResponse> response;
    if (externalResponse->hasError()) {
        // TODO temporarily take the error message as the output
        const std::shared_ptr<ErrorMessage>& error =
            externalResponse->getErrorMessage();
        const std::string& message = error->getErrorMessage();
        std::shared_ptr<MultiModalOutput> errorOutput =
            std::make_shared<TextMultiModalOutput>(message);
        std::shared_ptr<MultiModalOutputs> outputs =
            std::make_shared<MultiModalOutputs>();
        outputs->addMultiModalOutput(errorOutput);
        response =
            std::make_shared<ClientResponse>(externalResponse->getSessionId(),
                externalResponse->getRequestId(), outputs, nullptr, nullptr);
    } else {
        response =
            std::make_shared<ClientResponse>(externalResponse->getSessionId(),
            externalResponse->getRequestId(),
            externalResponse->getMultiModalOutputs(), nullptr, nullptr);
    }
    return response;
}

} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
