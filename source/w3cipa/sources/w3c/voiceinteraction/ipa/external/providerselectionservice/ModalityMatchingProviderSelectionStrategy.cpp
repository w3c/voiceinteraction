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

#include "ModalityMatchingProviderSelectionStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

ModalityMatchingProviderSelectionStrategy::ModalityMatchingProviderSelectionStrategy() {
}

const std::list<std::shared_ptr<ipa::IPAProvider>> ModalityMatchingProviderSelectionStrategy::filterIPAProviders(
    const std::list<std::shared_ptr<ipa::IPAProvider>>& providers,
    const std::shared_ptr<ClientRequest>& request) const {
    std::list<std::shared_ptr<ipa::IPAProvider>> filteredProviders;

    // Check which known provider supports the provided modalities
    const std::shared_ptr<MultiModalInputs> inputs =
        request->getMultiModalInputs();
    std::list<ModalityType> requestedTypes = inputs->getInputModalities();
    for (std::shared_ptr<ipa::IPAProvider> provider : providers) {
        std::list<ModalityType> supportedTypes =
            provider->getSupportedModalityTypes();
        if (isModalitySupported(requestedTypes, supportedTypes)) {
            filteredProviders.push_back(provider);
        }
    }

    return filteredProviders;
}

bool ModalityMatchingProviderSelectionStrategy::isModalitySupported(
    const std::list<ModalityType>& requestedTypes,
    const std::list<ModalityType>& supportedTypes) const {
    for (ModalityType requestedType : requestedTypes) {
        for (ModalityType supportedType : supportedTypes) {
            if (requestedType == supportedType) {
                return true;
            }
        }
    }
    return false;
}


} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
