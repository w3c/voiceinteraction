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

const std::shared_ptr<ClientResponse> ReferenceProviderSelectionService::processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData) {
    std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> providers =
        providerRegistry->getIPAProviders();
    for (std::shared_ptr<IPAProvider> provider : *providers) {
        return provider->processInput(sessionId, requestId, audioData,
                                      multiModalInputs, metaData);
    }
    return nullptr;
}


} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
