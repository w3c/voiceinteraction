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

#ifndef LANGUAGEMATCHINGPROVIDERSELECTIONSTRATEGY_H
#define LANGUAGEMATCHINGPROVIDERSELECTIONSTRATEGY_H

#include <w3c/voiceinteraction/ipa/Language.h>
#include <w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.h>

using namespace w3c::voiceinteraction::ipa;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * A provider selection strategy that will only those {@link IPAProvider}s
 * that are able to handle the language of the incoming request.
 *
 * @author Dirk Schnelle-Walka
 */
class LanguageMatchingProviderSelectionStrategy
    : public ::external::ipa::ProviderSelectionStrategy {
public:
    /**
     * Creates a new object.
     */
    LanguageMatchingProviderSelectionStrategy();

    const std::list<std::shared_ptr<::external::ipa::IPAProvider>> filterIPAProviders(
        const std::list<std::shared_ptr<::external::ipa::IPAProvider>>& providers,
        const std::shared_ptr<IPARequest>& request) const override;

private:
    /**
     * Checks if the requested types match those from the supported
     * @param requestedTypes requested modality types
     * @param supportedTypes supported modality types
     * @return
     */
    bool isLanguageSupported(
        const std::list<Language>& requestedLanguages,
        const std::list<Language>& supportedLanguages) const;
};

}  // namespace ipa
}  // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // LANGUAGEMATCHINGPROVIDERSELECTIONSTRATEGY_H
