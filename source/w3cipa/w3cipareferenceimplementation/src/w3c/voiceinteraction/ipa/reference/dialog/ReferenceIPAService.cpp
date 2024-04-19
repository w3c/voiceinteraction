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

#include <thread>

#include <log4cplus/loggingmacros.h>

#include <w3c/voiceinteraction/ipa/ClientResponse.h>

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

ReferenceIPAService::ReferenceIPAService() {
}

void  ReferenceIPAService::processIPAData(std::shared_ptr<IPAData> data) {
    if (const std::shared_ptr<ClientRequest>& request =
            std::dynamic_pointer_cast<ClientRequest>(data)) {
        processIPAData(request);
    } else if (const std::shared_ptr<ExternalClientResponse>& response =
            std::dynamic_pointer_cast<ExternalClientResponse>(data)) {
        processIPAData(response);
    } else {
        LOG4CPLUS_WARN(LOGGER,
            LOG4CPLUS_TEXT("No valid conversion for the received data"));
    }
}

void ReferenceIPAService::processIPAData(
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

    notifyListeners(request);
}

void ReferenceIPAService::processIPAData(
        const std::shared_ptr<ExternalClientResponse> &response) {
    std::shared_ptr<ClientResponse> forwardedResponse;
    if (response->hasError()) {
        // TODO temporarily take the error message as the output
        const std::shared_ptr<ErrorMessage>& error =
            response->getErrorMessage();
        const std::string& message = error->getErrorMessage();
        std::shared_ptr<MultiModalOutput> errorOutput =
            std::make_shared<TextMultiModalOutput>(message);
        std::shared_ptr<MultiModalOutputs> outputs =
            std::make_shared<MultiModalOutputs>();
        outputs->addMultiModalOutput(errorOutput);
        forwardedResponse =
            std::make_shared<ClientResponse>(response->getSessionId(),
                response->getRequestId(), outputs, nullptr, nullptr);
    } else {
        forwardedResponse =
            std::make_shared<ClientResponse>(response->getSessionId(),
            response->getRequestId(),
            response->getMultiModalOutputs(), nullptr, nullptr);
    }
    notifyListeners(forwardedResponse);
}


} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
