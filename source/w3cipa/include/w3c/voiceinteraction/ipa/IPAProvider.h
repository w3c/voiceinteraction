
#if !defined(IPAPROVIDER_H)
#define IPAPROVIDER_H

#include <string>

#include "ClientInput.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * Interface for IPA providers.
			 */
            class IPAProvider : public ClientInput
			{

			public:
            	/**
            	 * Constructs a new object.
            	 */
                IPAProvider() {
				}

                /**
                 * Destroys this object.
                 */
                virtual ~IPAProvider() {
				}

                /**
                 * Returns the IPA provider's ID.
                 * @return the IPA provider's ID.
                 */
                virtual const std::string getId() const = 0;
			};
		}
	}
}
#endif // !defined(IPAPROVIDER_H)
