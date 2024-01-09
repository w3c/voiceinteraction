#ifndef PROVIDERSELECTIONSERVICE_H
#define PROVIDERSELECTIONSERVICE_H

#include <memory>

#include "ClientInput.h"
#include "ProviderRegistry.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

class ProviderSelectionService : public ClientInput {
public:
    ProviderSelectionService(const std::shared_ptr<ProviderRegistry> registry)
        : providerRegistry(registry) {
    }

    virtual ~ProviderSelectionService() {
    }

protected:
    std::shared_ptr<ProviderRegistry> providerRegistry;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERSELECTIONSERVICE_H
