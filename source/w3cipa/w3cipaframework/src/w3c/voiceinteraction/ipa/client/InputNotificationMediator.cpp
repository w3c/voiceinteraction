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

#include "w3c/voiceinteraction/ipa/client/InputNotificationMediator.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

InputNotificationMediator::InputNotificationMediator() {
}

InputNotificationMediator::~InputNotificationMediator() {}

void InputNotificationMediator::addInputModalityComponentListener(
        const std::shared_ptr<InputModalityComponentListener>& listener) {
    inputListeners.push_back(listener);
}

void InputNotificationMediator::notifyListeners(
        std::shared_ptr<MultiModalInput> input) {
    for (const std::shared_ptr<InputModalityComponentListener>& listener : inputListeners) {
//        std::thread thread([&data, &listener]{
            listener->onMultiModalInput(input);
//        });
//        thread.join();
    }
}

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
