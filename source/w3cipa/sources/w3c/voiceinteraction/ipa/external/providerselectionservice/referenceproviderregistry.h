#ifndef REFERENCEPROVIDERREGISTRY_H
#define REFERENCEPROVIDERREGISTRY_H

#include <memory>
#include <list>

#include <w3c/voiceinteraction/ipa/IPAProvider.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

class ReferenceProviderRegistry {
public:
    ReferenceProviderRegistry();

    const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> getIPAProviders() const;

};

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEPROVIDERREGISTRY_H
