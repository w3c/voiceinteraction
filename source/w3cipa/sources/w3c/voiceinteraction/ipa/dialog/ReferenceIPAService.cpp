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
