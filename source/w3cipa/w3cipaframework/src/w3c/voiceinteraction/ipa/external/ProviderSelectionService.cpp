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

void ProviderSelectionService::addExternalClientResponseListener(
    const std::shared_ptr<ExternalClientResponseListener>& listener) {
    externalClientResponseListeners.push_back(listener);
}

void ProviderSelectionService::processInput(
    const std::shared_ptr<ClientRequest>& request) {
    std::list<std::shared_ptr<ExternalClientResponse>> responses;
    std::mutex mtx;
    std::condition_variable cv;

    std::list<std::shared_ptr<ExternalClientResponse>> errorResponses;
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
    for (const std::shared_ptr<ExternalClientResponseListener>& listener : externalClientResponseListeners) {
        for (const std::shared_ptr<ExternalClientResponse>& response : responses) {
            listener->processExternalClientResponse(response);
        }
    }
}

} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

