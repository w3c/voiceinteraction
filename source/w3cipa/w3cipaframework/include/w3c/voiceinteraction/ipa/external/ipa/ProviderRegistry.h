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

#ifndef PROVIDERREGISTRY_H
#define PROVIDERREGISTRY_H

#include <memory>
#include <list>

#include "IPAProvider.h"
#include "ProviderSelectionStrategy.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * @brief The ProviderRegistry class
 * This class knows all registered {@link IPAProvider}s and a
 * {@link ProviderSelectionStrategy} that will filter this list for
 * suitable IPAProviders for an actual request.
 *
 * A full list of known IPA
 * providers can be obtained via
 * {@link #getIPAProviders(const std::shared_ptr<ClientRequest>& request)}.
 *
 * New providers can be added via
 * {@link #addIPAProvider(const std::shared_ptr<IPAProvider>& provider)}.
 *
 * @author Dirk Schnelle-Walka
 */
class ProviderRegistry {
public:
    /**
     * Constructs a new object.
     */
    ProviderRegistry(const std::shared_ptr<ProviderSelectionStrategy>& strategy);

    /**
     * Destroys this object.
     */
    virtual ~ProviderRegistry();

    /**
     * Adds the IPA provider to the known IPA providers.
     * @param[in] provider the provider to add
     */
    void addIPAProvider(const std::shared_ptr<IPAProvider>& provider);

    /**
     * Returns a list of all registered IPA providers.
     * @param[in] request incoming request
     * @return A list of all registered IPA providers.
     */
    const std::list<std::shared_ptr<IPAProvider>> getIPAProviders(
        const std::shared_ptr<IPARequest>& request);

private:
    /** The strategy to determine the suitable IPA providers. */
    std::shared_ptr<ProviderSelectionStrategy> providerSelectionStrategy;

    /** Known IPA providers. */
    std::list<std::shared_ptr<IPAProvider>> providers;
};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERREGISTRY_H
