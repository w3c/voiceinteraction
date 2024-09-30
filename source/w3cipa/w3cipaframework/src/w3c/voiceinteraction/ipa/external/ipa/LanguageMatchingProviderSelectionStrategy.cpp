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

#include "w3c/voiceinteraction/ipa/external/ipa/LanguageMatchingProviderSelectionStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

LanguageMatchingProviderSelectionStrategy::
    LanguageMatchingProviderSelectionStrategy() {}

const std::list<std::shared_ptr<::external::ipa::IPAProvider>>
    LanguageMatchingProviderSelectionStrategy::filterIPAProviders(
    const std::list<std::shared_ptr<::external::ipa::IPAProvider>>& providers,
    const std::shared_ptr<ClientRequest>& request) const {
    std::list<std::shared_ptr<::external::ipa::IPAProvider>> filteredProviders;

    // Check which known provider supports the provided modalities
    const std::shared_ptr<MultiModalInputs> inputs =
        request->getMultiModalInputs();
    std::list<Language> requestedLangauges = inputs->getInputLanguages();
    for (const std::shared_ptr<::external::ipa::IPAProvider>& provider : providers) {
        // Check if the current provider supports the requested modalities
        std::list<Language> supportedLanguages =
            provider->getSupportedLanguages();
        if (isLanguageSupported(requestedLangauges, supportedLanguages)) {
            filteredProviders.push_back(provider);
        }
    }

    return filteredProviders;
}

bool LanguageMatchingProviderSelectionStrategy::isLanguageSupported(
    const std::list<Language>& requestedLanguages,
    const std::list<Language>& supportedLanguages) const {
  for (const Language& requestedLanguage : requestedLanguages) {
    // Check if the requested language is supported
    for (const Language& supportedLanguage : supportedLanguages) {
      if (requestedLanguage == supportedLanguage) {
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
