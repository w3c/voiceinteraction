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

#include "w3c/voiceinteraction/ipa/external/ipa/IPAProvider.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {

/**
 * @brief The ProviderRegistry class
 * This class knows all registered IPA providers.
 * @author Dirk Schnelle-Walka
 */
class ProviderRegistry {
public:
    /**
     * Constructs a new object.
     */
    ProviderRegistry() {
    }

    /**
     * Destroys this object.
     */
    virtual ~ProviderRegistry() {
    }

    /**
     * Returns a list of all registered IPA providers.
     *
     * @return A list of all registered IPA providers.
     */
    virtual const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> getIPAProviders() const = 0;

};

} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERREGISTRY_H
