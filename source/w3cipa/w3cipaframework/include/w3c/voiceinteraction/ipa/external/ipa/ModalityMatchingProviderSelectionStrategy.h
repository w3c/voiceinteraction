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

#ifndef MODALITYMATCHINGPROVIDERSELECTIONSTRATEGY_H
#define MODALITYMATCHINGPROVIDERSELECTIONSTRATEGY_H

#include <w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.h>

using namespace w3c::voiceinteraction::ipa;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * A provider selection strategy that will only those {@link IPAProvider}s
 * that are able to handle the modalities of the incoming request.
 *
 * @author Dirk Schnelle-Walka
 */
class ModalityMatchingProviderSelectionStrategy
    : public ::external::ipa::ProviderSelectionStrategy {
public:
    /**
     * Creates a new object.
     */
    ModalityMatchingProviderSelectionStrategy();

    /**
     * {@inheritDoc}
     */
    const std::list<std::shared_ptr<::external::ipa::IPAProvider>>
    filterIPAProviders(
        const std::list<std::shared_ptr<::external::ipa::IPAProvider>>& providers,
        const std::shared_ptr<IPARequest>& request) const override;

private:
    /**
     * Checks if the requested types match those from the supported
     * @param requestedTypes requested modality types
     * @param supportedTypes supported modality types
     * @return
     */
    bool isModalitySupported(const std::list<ModalityType>& requestedTypes,
                             const std::list<ModalityType>& supportedTypes) const;
};

}  // namespace ipa
}  // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // MODALITYMATCHINGPROVIDERSELECTIONSTRATEGY_H
