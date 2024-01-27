///////////////////////////////////////////////////////////
//  RequestId.h
//  Implementation of the Interface RequestId
//  Created on:      13-Jun-2023 20:55:10
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_3182575A_C3AE_4d3f_93CF_9488CA7EFE9C__INCLUDED_)
#define EA_3182575A_C3AE_4d3f_93CF_9488CA7EFE9C__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * The request id is used to identify a request. It is used to match a request
			 * with a response.
			 */
			class RequestId
			{

			public:
				/**
				 * Constructs a new request id.
				 */
				RequestId() {
				}

				/**
				 * Destroys the request id.
				 */
				virtual ~RequestId() {
				}

			};

		}

	}

}
#endif // !defined(EA_3182575A_C3AE_4d3f_93CF_9488CA7EFE9C__INCLUDED_)
