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

const std::list<std::shared_ptr<ExternalClientResponse>> ProviderSelectionService::processInput(
    const std::shared_ptr<ClientRequest>& request) {
    std::list<std::shared_ptr<ExternalClientResponse>> responses;
    std::list<std::shared_ptr<IPAProvider>> providers =
        providerRegistry->getIPAProviders(request);
    for (std::shared_ptr<IPAProvider> provider : providers) {
        // TODO check to call the IPA providers asynchronously
        std::shared_ptr<ExternalClientResponse> response =
            provider->processInput(request);
        if (response != nullptr) {
            responses.push_back(response);
        }
    }
    return responses;
}

} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

