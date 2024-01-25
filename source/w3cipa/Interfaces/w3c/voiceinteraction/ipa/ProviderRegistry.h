#ifndef PROVIDERREGISTRY_H
#define PROVIDERREGISTRY_H

#include <memory>
#include <list>

#include <w3c/voiceinteraction/ipa/IPAProvider.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief The ProviderRegistry class
 * This class knows all registered IPA providers.
 */
class ProviderRegistry {
public:
	/**
	 * Constructs a new object.
	 */
    ProviderRegistry() {
    }

    /**
     * Destroys this object.
     */
    virtual ~ProviderRegistry() {
    }

	/**
	 * Returns a list of all registered IPA providers.
	 *
	 * @return A list of all registered IPA providers.
	 */
    virtual const std::shared_ptr<std::list<std::shared_ptr<IPAProvider>>> getIPAProviders() const = 0;

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PROVIDERREGISTRY_H
