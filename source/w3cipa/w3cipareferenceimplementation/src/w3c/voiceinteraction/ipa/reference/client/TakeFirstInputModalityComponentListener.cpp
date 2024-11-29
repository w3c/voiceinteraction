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

#include <iostream>
#include <log4cplus/loggingmacros.h>

#include <w3c/voiceinteraction/ipa/IPARequest.h>

#include "w3c/voiceinteraction/ipa/reference/IntegerRequestId.h"
#include "w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

const log4cplus::Logger TakeFirstInputModalityComponentListener::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.ipa.dialog.TakeFirstInputModalityComponentListener"));

TakeFirstInputModalityComponentListener::TakeFirstInputModalityComponentListener() {
}

void TakeFirstInputModalityComponentListener::processIPAData(
        std::shared_ptr<IPAData> data) {
    LOG4CPLUS_INFO(LOGGER,
                   LOG4CPLUS_TEXT("waiting for input"));
    std::shared_ptr<MultiModalInputs> multiModalInputs = getMultiModalInputs();
    std::shared_ptr<w3c::voiceinteraction::ipa::RequestId> requestId =
        std::make_shared<IntegerRequestId>();
    std::shared_ptr<MetaData> metaData = std::make_shared<MetaData>();
    std::shared_ptr<IPAData> request =
        std::make_shared<IPARequest>(nullptr, requestId, multiModalInputs,
            nullptr, metaData);
    LOG4CPLUS_INFO(LOGGER,
                   LOG4CPLUS_TEXT("forwarding first input"));
    notifyListeners(request);
}

void TakeFirstInputModalityComponentListener::onMultiModalInput(
        std::shared_ptr<MultiModalInput> input) {
    std::unique_lock<std::mutex> lck(mtx);
    multiModalInput = input;
    cv.notify_one();
}

std::shared_ptr<MultiModalInputs> TakeFirstInputModalityComponentListener::getMultiModalInputs() {
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [this] {
        return multiModalInput != nullptr;
    });

    std::shared_ptr<MultiModalInputs> multiModalInputs =
        std::make_shared<MultiModalInputs>();
    multiModalInputs->addMultiModalInput(multiModalInput);
    return multiModalInputs;
}

} // namespace client
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
