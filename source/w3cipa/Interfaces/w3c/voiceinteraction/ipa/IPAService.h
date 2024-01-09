#ifndef IPASERVICE_H
#define IPASERVICE_H

#include <memory>

#include "ClientInput.h"
#include "ProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

class IPAService : public ClientInput {
public:
    IPAService(const std::shared_ptr<ProviderSelectionService>& service)
        : providerSelectionService(service) {
    }

    virtual ~IPAService() {
    }

protected:
    std::shared_ptr<ProviderSelectionService> providerSelectionService;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPASERVICE_H
