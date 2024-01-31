#ifndef REFERENCEIPASERVICE_H
#define REFERENCEIPASERVICE_H

#include <memory>

#include <w3c/voiceinteraction/ipa/IPAService.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

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
