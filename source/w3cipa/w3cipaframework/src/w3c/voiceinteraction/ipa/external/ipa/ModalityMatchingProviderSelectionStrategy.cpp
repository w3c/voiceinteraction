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

#include "w3c/voiceinteraction/ipa/external/ipa/ModalityMatchingProviderSelectionStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

ModalityMatchingProviderSelectionStrategy::ModalityMatchingProviderSelectionStrategy() {
}

const std::list<std::shared_ptr<::external::ipa::IPAProvider>> ModalityMatchingProviderSelectionStrategy::filterIPAProviders(
    const std::list<std::shared_ptr<::external::ipa::IPAProvider>>& providers,
    const std::shared_ptr<IPARequest>& request) const {
    std::list<std::shared_ptr<::external::ipa::IPAProvider>> filteredProviders;

    // Check which known provider supports the provided modalities
    const std::shared_ptr<MultiModalDataCollection> inputs =
        request->getMultiModalInputs();
    std::list<ModalityType> requestedTypes = inputs->getMultiModalData();
    for (const std::shared_ptr<::external::ipa::IPAProvider>& provider : providers) {
        // Check if the current provider supports the requested modalities
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
    for (const ModalityType& requestedType : requestedTypes) {
        // Check if the requested type is supported
        for (const ModalityType& supportedType : supportedTypes) {
            if (requestedType == supportedType) {
                return true;
            }
        }
    }
    return false;
}

}  // namespace ipa
}  // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
