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

#include "w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

ProviderRegistry::ProviderRegistry(const std::shared_ptr<ProviderSelectionStrategy>& strategy)
    : providerSelectionStrategy(strategy) {
}

ProviderRegistry::~ProviderRegistry() {
}

void ProviderRegistry::addIPAProvider(const std::shared_ptr<IPAProvider>& provider) {
    providers.push_back(provider);
}

const std::list<std::shared_ptr<IPAProvider>> ProviderRegistry::getIPAProviders(
    const std::shared_ptr<IPARequest>& request) {
    return providerSelectionStrategy->filterIPAProviders(providers,
                                                         request);
}

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
