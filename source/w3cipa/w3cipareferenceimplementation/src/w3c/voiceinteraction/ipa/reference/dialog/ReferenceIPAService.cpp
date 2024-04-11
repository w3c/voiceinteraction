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

ReferenceIPAService::ReferenceIPAService(
    const std::shared_ptr<ProviderSelectionService> &service)
    : IPAService(service) {
}

void  ReferenceIPAService::processIPAData(std::shared_ptr<IPAData> data) {
    if (std::shared_ptr<ClientRequest> request =
            std::dynamic_pointer_cast<ClientRequest>(data)) {
        processIPAData(request);
    } else if (std::shared_ptr<ExternalClientResponse> response =
            std::dynamic_pointer_cast<ExternalClientResponse>(data)) {
        processIPAData(response);
    } else {
        LOG4CPLUS_WARN(LOGGER,
            LOG4CPLUS_TEXT("No valid conversion for the received data"));
    }
}

void ReferenceIPAService::processIPAData(
    std::shared_ptr<ClientRequest> request) {
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

    // Asynchronously call the the external IPAs
    std::thread thread([&] {
        providerSelectionService->processInput(request);
    });
    thread.detach();

    // Wait for the input
    CombinedId combinedId(request->getSessionId(), request->getRequestId());
    std::shared_ptr<ExternalClientResponse> externalResponse = nullptr;
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&] {
        std::map<CombinedId, std::shared_ptr<ExternalClientResponse>>::iterator iterator =
                externalResponses.find(combinedId);
        if (iterator == externalResponses.end()) {
            return false;
        }
        externalResponse = iterator->second;
        externalResponses.erase(iterator);
        return true;
    });

    if (externalResponse == nullptr) {
        LOG4CPLUS_ERROR(LOGGER, LOG4CPLUS_TEXT("No valid response received"));
        return;
    }

    // Create a reply to the client
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
    notifyListeners(response);
}

void ReferenceIPAService::processIPAData(
        std::shared_ptr<ExternalClientResponse> response) {
    std::unique_lock<std::mutex> lck(mtx);
    CombinedId combinedId(response->getSessionId(), response->getRequestId());
    externalResponses[combinedId] = response;
    cv.notify_one();
}


} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
