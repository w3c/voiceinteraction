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

#include "../ipa/chatgpt/ChatGPTAdapter.h"

#include "ReferenceProviderRegistry.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

ReferenceProviderRegistry::ReferenceProviderRegistry() {

}

const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> ReferenceProviderRegistry::getIPAProviders() const {
    std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> providers =
        std::make_shared<std::list<std::shared_ptr<IPAProvider>>>();
    std::shared_ptr<IPAProvider> chatgpt =
        std::make_shared<ipa::chatgpt::ChatGPTAdapter>();
    providers->push_back(chatgpt);
    return providers;
}

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
