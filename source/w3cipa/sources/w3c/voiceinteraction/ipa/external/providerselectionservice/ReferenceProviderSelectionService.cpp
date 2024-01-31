#include "ReferenceProviderRegistry.h"
#include "ReferenceProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

ReferenceProviderSelectionService::ReferenceProviderSelectionService()
    : ProviderSelectionService(std::make_shared<ReferenceProviderRegistry>()) {
}

const std::shared_ptr<ClientResponse> ReferenceProviderSelectionService::processInput(
    const std::shared_ptr<ClientRequest> &request) {
    std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> providers =
        providerRegistry->getIPAProviders();
    for (const std::shared_ptr<IPAProvider>& provider : *providers) {
        return provider->processInput(request);
    }
    return nullptr;
}


} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
