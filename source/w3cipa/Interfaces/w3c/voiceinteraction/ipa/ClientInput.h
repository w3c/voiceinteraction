///////////////////////////////////////////////////////////
//  ClientInput.h
//  Implementation of the Interface ClientInput
//  Created on:      13-Jun-2023 21:09:30
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)
#define EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_

#include <memory>

#include "SessionId.h"
#include "RequestId.h"
#include "AudioData.h"
#include "MultiModalInputs.h"
#include "MetaData.h"
#include "ClientResponse.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			class ClientInput
			{

			public:
				ClientInput() {

				}

                virtual ~ClientInput() {
                };

                virtual const std::shared_ptr<ClientResponse> processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData) =0;

			};

		}

	}

}
#endif // !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)