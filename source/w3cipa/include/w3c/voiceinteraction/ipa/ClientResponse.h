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
			/**
			 * This interface is used to return the results of a request to the client.
			 */
			class ClientResponse
			{

            public:
				/**
				 * Constructs a new object.
				 * @param multiModalOutputs The multimodal outputs to be returned to the client.
				 */
                ClientResponse(const std::shared_ptr<MultiModalOutputs>& multiModalOutputs)
                    : outputs(multiModalOutputs) {
				}

                /**
                 * Destroys the object.
                 */
				virtual ~ClientResponse() {

				}

				/**
				 * Returns the audio data to be played to the user.
				 * @return The audio data to be played to the user.
				 */
				virtual const AudioData& getAudioData() =0;

				/**
				 * Returns the multimodal outputs to be returned to the client.
				 * qreturn The multimodal outputs to be returned to the client.
				 */
                virtual const std::shared_ptr<MultiModalOutputs> getMultiModalOutputs() {
                    return outputs;
                }

                /**
                 * Returns the request id of the request this response belongs to.
                 * @return The request id of the request this response belongs to.
                 */
				virtual const RequestId& getRequestId() =0;

				/**
				 * Returns the session id of the session this response belongs to.
				 * @return The session id of the session this response belongs to.
				 */
                virtual const SessionId& getSessionId() =0;

            private:
                /**
                 * The multimodal outputs to be returned to the client.
                 */
                std::shared_ptr<MultiModalOutputs> outputs;
			};

		}

	}

}
#endif // !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
