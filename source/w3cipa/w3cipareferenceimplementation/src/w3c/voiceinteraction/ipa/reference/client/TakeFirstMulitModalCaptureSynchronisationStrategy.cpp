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

#include "w3c/voiceinteraction/ipa/reference/client/TakeFirstMulitModalCaptureSynchronisationStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

const log4cplus::Logger TakeFirstMulitModalCaptureSynchronisationStrategy::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.ipa.dialog.TakeFirstInputModalityComponentListener"));

TakeFirstMulitModalCaptureSynchronisationStrategy::
    TakeFirstMulitModalCaptureSynchronisationStrategy(
        const std::shared_ptr<::client::InteractionManager>& im) 
    : ::client::MulitModalCaptureSynchronisationStrategy(im) {}

void TakeFirstMulitModalCaptureSynchronisationStrategy::onMultiModalInput(
        std::shared_ptr<MultiModalData> input) {
  std::shared_ptr<MultiModalDataCollection> multiModalInputs =
      std::make_shared<MultiModalDataCollection>();
  multiModalInputs->addMultiModalData(input);
  LOG4CPLUS_INFO(LOGGER, LOG4CPLUS_TEXT("forwarding first input"));
  notifyInteractionManager(multiModalInputs);
}


} // namespace client
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
