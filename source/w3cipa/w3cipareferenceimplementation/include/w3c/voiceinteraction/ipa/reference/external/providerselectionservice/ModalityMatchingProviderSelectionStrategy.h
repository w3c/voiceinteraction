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
namespace reference {
namespace external {
namespace providerselectionservice {

class ModalityMatchingProviderSelectionStrategy
    : public ::external::ipa::ProviderSelectionStrategy
{
public:
    ModalityMatchingProviderSelectionStrategy();

    const std::list<std::shared_ptr<::external::ipa::IPAProvider>> filterIPAProviders(
        const std::list<std::shared_ptr<::external::ipa::IPAProvider>>& providers,
        const std::shared_ptr<ClientRequest>& request) const;

private:
    bool isModalitySupported(const std::list<ModalityType>& requestedTypes,
                             const std::list<ModalityType>& supportedTypes) const;
};

} // namespace providerselectionservice
} // namespace external
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // MODALITYMATCHINGPROVIDERSELECTIONSTRATEGY_H
