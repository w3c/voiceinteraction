///////////////////////////////////////////////////////////
//  ClientResponse.h
//  Implementation of the Interface ClientResponse
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
#define EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_

#include <memory>

#include "AudioData.h"
#include "MultiModalOutputs.h"
#include "RequestId.h"
#include "SessionId.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			class ClientResponse
			{

            public:
                ClientResponse(const std::shared_ptr<MultiModalOutputs>& multiModalOutputs)
                    : outputs(multiModalOutputs) {

				}

				virtual ~ClientResponse() {

				}

				virtual const AudioData& getAudioData() =0;

                virtual const std::shared_ptr<MultiModalOutputs> getMultiModalOutputs() {
                    return outputs;
                }

				virtual const RequestId& getRequestId() =0;
                virtual const SessionId& getSessionId() =0;

            private:
                std::shared_ptr<MultiModalOutputs> outputs;
			};

		}

	}

}
#endif // !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
