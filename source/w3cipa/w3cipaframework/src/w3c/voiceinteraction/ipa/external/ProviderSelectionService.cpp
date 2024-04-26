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

#include <mutex>
#include <condition_variable>
#include <thread>

#include "w3c/voiceinteraction/ipa/external/ProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {

ProviderSelectionService::ProviderSelectionService(const std::shared_ptr<ProviderRegistry> registry)
    : providerRegistry(registry) {
}

ProviderSelectionService::~ProviderSelectionService() {
}

void ProviderSelectionService::processIPAData(
        std::shared_ptr<IPAData> data) {
    // Only reply to calls that can be understood
    std::shared_ptr<ClientRequest> request =
            std::dynamic_pointer_cast<ClientRequest>(data);
    if (request == nullptr) {
        return;
    }

    // Mutex and condition var to be able to delay until all replies have
    // been received
    std::mutex mtx;
    std::condition_variable cv;

    // Valid responses will be caught here
    std::list<std::shared_ptr<ExternalClientResponse>> responses;
    // All erroroneous calls will be caught here
    std::list<std::shared_ptr<ExternalClientResponse>> errorResponses;

    // Asynchronously call all providers that the provider registry finds
    // adequate for this request
    std::list<std::shared_ptr<IPAProvider>> providers =
        providerRegistry->getIPAProviders(request);
    for (std::shared_ptr<IPAProvider>& provider : providers) {
        std::thread thread([&] {
            std::shared_ptr<ExternalClientResponse> response =
                provider->processInput(request);
            std::unique_lock<std::mutex> lck(mtx);
            if (response->hasError()) {
                errorResponses.push_back(response);
            } else {
                responses.push_back(response);
            }
            cv.notify_one();
        });
        thread.detach();
    }

    // Delay until we have all replies
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, [&] {
        return responses.size() + errorResponses.size() == providers.size();
    });

    // In case there is no positive response, return all error responses
    // Otherwise, these will be ignored, taking only the successful ones.
    if (responses.empty()) {
        responses = errorResponses;
    }

    // Notify all listeners about the results.
    for (const std::shared_ptr<ExternalClientResponse>& response : responses) {
        notifyListeners(response);
    }
}

} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

