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

#include "w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategyList.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

ProviderSelectionStrategyList::ProviderSelectionStrategyList() {
}

ProviderSelectionStrategyList::~ProviderSelectionStrategyList() {
}

void ProviderSelectionStrategyList::addStrategy(
    const std::shared_ptr<ProviderSelectionStrategy>& strategy) {
    strategies.push_back(strategy);
}

const std::list<std::shared_ptr<IPAProvider>>
ProviderSelectionStrategyList::filterIPAProviders(
    const std::list<std::shared_ptr<IPAProvider>>& providers,
    const std::shared_ptr<ClientRequest>& request) const {
    std::list<std::shared_ptr<IPAProvider>> filteredProviders = providers;
    for (const std::shared_ptr<ProviderSelectionStrategy>& strategy :
         strategies) {
        filteredProviders =
            strategy->filterIPAProviders(filteredProviders, request);
    }
    return filteredProviders;
}

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
