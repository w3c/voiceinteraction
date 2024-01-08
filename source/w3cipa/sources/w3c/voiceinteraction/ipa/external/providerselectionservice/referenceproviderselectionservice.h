#ifndef REFERENCEPROVIDERSELECTIONSERVICE_H
#define REFERENCEPROVIDERSELECTIONSERVICE_H

#include <w3c/voiceinteraction/ipa/ClientInput.h>

#include "referenceproviderregistry.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

class ReferenceProviderSelectionService : public ClientInput {
public:
    ReferenceProviderSelectionService();

    const std::shared_ptr<ClientResponse> processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData);

private:
    std::shared_ptr<ReferenceProviderRegistry> providerRegistry;
};

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEPROVIDERSELECTIONSERVICE_H
