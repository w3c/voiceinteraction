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

#ifndef PROVIDERSELECTIONSTRATEGY_H
#define PROVIDERSELECTIONSTRATEGY_H

#include <memory>
#include <list>

#include "w3c/voiceinteraction/ipa/ClientRequest.h"
#include "IPAProvider.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * Strategy to determine which IPA provider to use.
 * @author Dirk Schnelle-Walka
 */
class ProviderSelectionStrategy {
public:
    /**
     * Constructs a new object.
     */
    ProviderSelectionStrategy();

    /**
     * Destroys this instance.
     */
    virtual ~ProviderSelectionStrategy();

    /**
     * Returns a list of all applicable IPA providers.
     * @param providers the original list of IPA providers
     * @param request the incoming request from the client
     * @return A list of all registered IPA providers.
     */
    virtual const std::list<std::shared_ptr<IPAProvider>> filterIPAProviders(
        const std::list<std::shared_ptr<IPAProvider>>& providers,
        const std::shared_ptr<ClientRequest>& request) const = 0;
};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERSELECTIONSTRATEGY_H
