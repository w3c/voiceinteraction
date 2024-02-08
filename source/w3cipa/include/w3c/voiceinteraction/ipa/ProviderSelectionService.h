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

#ifndef PROVIDERSELECTIONSERVICE_H
#define PROVIDERSELECTIONSERVICE_H

#include <memory>

#include "ClientInput.h"
#include "ProviderRegistry.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief The ProviderSelectionService class is a base class for all services
 *        that need to select a provider based on the input.
 *
 * The ProviderSelectionService is a base class for all services that need to
 * select a provider based on the input. It provides a ProviderRegistry to get
 * the list of available providers.
 * @author Dirk Schnelle-Walka
 */
class ProviderSelectionService : public ClientInput {
public:
    /**
     * Constructs a new object.
     */
    ProviderSelectionService(const std::shared_ptr<ProviderRegistry> registry)
        : providerRegistry(registry) {
    }

    /**
     * Destroys the object.
     */
    virtual ~ProviderSelectionService() {
    }

protected:
    /** The provider registry. */
    std::shared_ptr<ProviderRegistry> providerRegistry;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERSELECTIONSERVICE_H
