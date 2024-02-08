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

#ifndef REFERENCEIPASERVICE_H
#define REFERENCEIPASERVICE_H

#include <memory>

#include <w3c/voiceinteraction/ipa/external/ipa/IPAService.h>

using namespace w3c::voiceinteraction::ipa::external;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

/**
 * @brief A reference implementation of an IPA Service
 * @author Dirk Schnelle-Walka
 */
class ReferenceIPAService : public IPAService {
public:
    ReferenceIPAService(const std::shared_ptr<ProviderSelectionService>& service);
    const std::shared_ptr<ClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request);
};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEIPASERVICE_H
