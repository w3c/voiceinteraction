///////////////////////////////////////////////////////////
//  ClientResponse.h
//  Implementation of the Interface ClientResponse
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
#define EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			class ClientResponse
			{

			public:
				ClientResponse() {

				}

				virtual ~ClientResponse() {

				}

				virtual const AudioData& getAudioData() =0;
				virtual const MultiModalOutput& getMultiModalOutput() =0;
				virtual const RequestId& getRequestId() =0;
				virtual const SessionId& getSessionId() =0;

			};

		}

	}

}
#endif // !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
