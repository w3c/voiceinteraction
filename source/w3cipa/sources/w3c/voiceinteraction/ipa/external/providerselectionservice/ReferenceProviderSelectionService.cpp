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

#include "ReferenceProviderRegistry.h"
#include "ReferenceProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

ReferenceProviderSelectionService::ReferenceProviderSelectionService()
    : ProviderSelectionService(std::make_shared<ReferenceProviderRegistry>()) {
}

const std::shared_ptr<ClientResponse> ReferenceProviderSelectionService::processInput(
    const std::shared_ptr<ClientRequest> &request) {
    std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> providers =
        providerRegistry->getIPAProviders();
    for (const std::shared_ptr<IPAProvider>& provider : *providers) {
        return provider->processInput(request);
    }
    return nullptr;
}


} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
