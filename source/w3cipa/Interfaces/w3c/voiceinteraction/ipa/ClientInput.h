///////////////////////////////////////////////////////////
//  ClientInput.h
//  Implementation of the Interface ClientInput
//  Created on:      13-Jun-2023 21:09:30
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)
#define EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_

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

				virtual ~ClientInput() =0;
				virtual const ClientResponse& processInput(const SessionId& sessionId, const RequestId& requestId, const AudioData& audioData, const MultiModalInput& multiModalInput, const MetaData& metaData) =0;

			};

		}

	}

}
#endif // !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)
