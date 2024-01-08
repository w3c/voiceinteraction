#include "referenceproviderregistry.h"

#include "../ipa/chatgpt/chatgptadapter.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace providerselectionservice {

ReferenceProviderRegistry::ReferenceProviderRegistry() {

}

const std::shared_ptr<std::list<std::shared_ptr<IPAProvider> > > ReferenceProviderRegistry::getIPAProviders() const {
    std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> providers = std::make_shared<std::list<std::shared_ptr<IPAProvider>>>();
    std::shared_ptr<IPAProvider> chatgpt = std::make_shared<ipa::chatgpt::ChatGPTAdapter>();
    providers->push_back(chatgpt);
    return providers;
}

} // namespace providerselectionservice
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
