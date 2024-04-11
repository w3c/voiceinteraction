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

#include "w3c/voiceinteraction/ipa/IPADataProcessor.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

IPADataProcessor::IPADataProcessor() {
}

IPADataProcessor::~IPADataProcessor() {
}

void IPADataProcessor::addIPADataProcessorListener(
        const std::shared_ptr<IPADataProcessor>& listener) {
    listeners.push_back(listener);
}

void IPADataProcessor::notifyListeners(std::shared_ptr<IPAData> data) {
    for (const std::shared_ptr<IPADataProcessor>& listener : listeners) {
        std::thread thread([&data, &listener]{
            listener->processIPAData(data);
        });
        thread.join();
    }
}


} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
