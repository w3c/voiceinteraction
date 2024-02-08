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

#include "ReferenceIPAService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

ReferenceIPAService::ReferenceIPAService(const std::shared_ptr<ProviderSelectionService> &service)
    : IPAService(service) {
}

const std::shared_ptr<ClientResponse> ReferenceIPAService::processInput(const std::shared_ptr<ClientRequest> &request) {
    return providerSelectionService->processInput(request);
}

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
