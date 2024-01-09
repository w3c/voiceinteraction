#ifndef REFERENCEIPASERVICE_H
#define REFERENCEIPASERVICE_H

#include <memory>

#include <w3c/voiceinteraction/ipa/ClientInput.h>

#include "../external/providerselectionservice/referenceproviderselectionservice.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

class ReferenceIPAService : public ClientInput {
public:
    ReferenceIPAService(const std::shared_ptr<external::providerselectionservice::ReferenceProviderSelectionService>& service);
    const std::shared_ptr<ClientResponse> processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData);

private:
    std::shared_ptr<external::providerselectionservice::ReferenceProviderSelectionService> providerSelectionService;
};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEIPASERVICE_H
