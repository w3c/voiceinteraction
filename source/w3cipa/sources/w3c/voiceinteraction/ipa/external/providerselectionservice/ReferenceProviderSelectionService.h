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

#ifndef REFERENCEPROVIDERSELECTIONSERVICE_H
#define REFERENCEPROVIDERSELECTIONSERVICE_H

#include <w3c/voiceinteraction/ipa/ProviderSelectionService.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

/**
 * @brief Reference implementation of a provider selection service.
 * @author Dirk Schnelle-Walka
 */
class ReferenceProviderSelectionService : public ProviderSelectionService {
public:
    ReferenceProviderSelectionService();

    const std::shared_ptr<ClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request);
};

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEPROVIDERSELECTIONSERVICE_H
