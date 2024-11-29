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

#ifndef PROVIDERSELECTIONSTRATEGYLIST_H
#define PROVIDERSELECTIONSTRATEGYLIST_H

#include <list>

#include "ProviderSelectionStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * Strategy to determine which IPA provider to use.
 * @author Dirk Schnelle-Walka
 */
class ProviderSelectionStrategyList : public ProviderSelectionStrategy {
public:
    /**
     * Constructs a new object.
     */
    ProviderSelectionStrategyList();

    /**
     * Destroys this instance.
     */
    virtual ~ProviderSelectionStrategyList();

    /**
     * Adds a new strategy to the list.
     * @param strategy the new strategy to add
     */
    void addStrategy(
        const std::shared_ptr<ProviderSelectionStrategy>& strategy);

    /**
     * Returns a list of all applicable IPA providers.
     * @param[in] providers the original list of IPA providers
     * @param[in] request the incoming request from the client
     * @return A list of all registered IPA providers.
     */
    const std::list<std::shared_ptr<IPAProvider>> filterIPAProviders(
        const std::list<std::shared_ptr<IPAProvider>>& providers,
        const std::shared_ptr<IPARequest>& request) const;

private:
    /** Known provider selection strategies. */
    std::list<std::shared_ptr<ProviderSelectionStrategy>> strategies;
};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERSELECTIONSTRATEGYLIST_H
