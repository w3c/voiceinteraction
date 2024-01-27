#ifndef IPASERVICE_H
#define IPASERVICE_H

#include <memory>

#include "ClientInput.h"
#include "ProviderSelectionService.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief The IPAService class
 * The IPAService is the base class for the IPA service.
 */
class IPAService : public ClientInput {
public:
	/**
	 * Constructs a new object.
	 * @param service The provider selection service.
	 */
    IPAService(const std::shared_ptr<ProviderSelectionService>& service)
        : providerSelectionService(service) {
    }

	/**
	 * Destroys the object.
	 */
    virtual ~IPAService() {
    }

protected:
	/**
	 * @brief providerSelectionService The provider selection service.
	 */
    std::shared_ptr<ProviderSelectionService> providerSelectionService;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPASERVICE_H
