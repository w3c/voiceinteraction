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

#ifndef REFERENCEPROVIDERREGISTRY_H
#define REFERENCEPROVIDERREGISTRY_H

#include <memory>
#include <list>

#include <w3c/voiceinteraction/ipa/ProviderRegistry.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

/**
 * @brief Reference implementation of a provider registry.
 * @author Dirk Schnelle-Walka
 */
class ReferenceProviderRegistry : public ProviderRegistry {
public:
    ReferenceProviderRegistry();

    const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> getIPAProviders() const;

};

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEPROVIDERREGISTRY_H
