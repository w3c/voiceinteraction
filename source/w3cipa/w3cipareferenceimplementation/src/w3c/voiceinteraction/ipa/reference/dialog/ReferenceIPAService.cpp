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

#include <w3c/voiceinteraction/ipa/IPAResponse.h>

#include "w3c/voiceinteraction/ipa/reference/UUIDSessionId.h"
#include "w3c/voiceinteraction/ipa/reference/TextMultiModalData.h"
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
    if (const std::shared_ptr<IPARequest>& request =
        std::dynamic_pointer_cast<IPARequest>(data)) {
        processIPAData(request);
    } else if (const std::shared_ptr<IPAResponse>& response =
        std::dynamic_pointer_cast<IPAResponse>(data)) {
        processIPAData(response);
    } else {
        LOG4CPLUS_WARN(LOGGER,
            LOG4CPLUS_TEXT("No valid conversion for the received data"));
    }
}

void ReferenceIPAService::processIPAData(
        const std::shared_ptr<IPARequest> &request) {
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
    const std::shared_ptr<IPAResponse>& response) {
    notifyListeners(response);
}

} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
