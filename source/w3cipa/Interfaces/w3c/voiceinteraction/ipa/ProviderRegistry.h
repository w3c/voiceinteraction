#ifndef PROVIDERREGISTRY_H
#define PROVIDERREGISTRY_H

#include <memory>
#include <list>

#include <w3c/voiceinteraction/ipa/IPAProvider.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

class ProviderRegistry {
public:
    ProviderRegistry() {
    }

    virtual ~ProviderRegistry() {
    }

    virtual const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> getIPAProviders() const = 0;

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERREGISTRY_H
