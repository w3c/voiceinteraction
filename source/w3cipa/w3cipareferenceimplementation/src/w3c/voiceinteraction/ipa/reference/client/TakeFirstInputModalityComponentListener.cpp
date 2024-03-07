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

#include "w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

TakeFirstInputModalityComponentListener::TakeFirstInputModalityComponentListener() {
}

void TakeFirstInputModalityComponentListener::onMultiModalInput(
    std::shared_ptr<MultiModalInput>& input) {
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
