#include "referenceipaservice.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

ReferenceIPAService::ReferenceIPAService(const std::shared_ptr<ProviderSelectionService> &service)
    : IPAService(service) {
}

const std::shared_ptr<ClientResponse> ReferenceIPAService::processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData) {
    return providerSelectionService->processInput( sessionId, requestId, audioData, multiModalInputs, metaData);
}

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
