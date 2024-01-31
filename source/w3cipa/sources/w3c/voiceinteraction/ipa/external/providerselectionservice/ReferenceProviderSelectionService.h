#ifndef REFERENCEPROVIDERSELECTIONSERVICE_H
#define REFERENCEPROVIDERSELECTIONSERVICE_H

#include <w3c/voiceinteraction/ipa/ProviderSelectionService.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

class ReferenceProviderSelectionService : public ProviderSelectionService {
public:
    ReferenceProviderSelectionService();

    const std::shared_ptr<ClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request);
};

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEPROVIDERSELECTIONSERVICE_H
