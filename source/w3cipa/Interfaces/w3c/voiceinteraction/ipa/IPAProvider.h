
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
            class IPAProvider : public ClientInput
			{

			public:
                IPAProvider() {
				}

                virtual ~IPAProvider() {
				}

                virtual const std::string getId() const = 0;

			};

		}

	}

}
#endif // !defined(IPAPROVIDER_H)
