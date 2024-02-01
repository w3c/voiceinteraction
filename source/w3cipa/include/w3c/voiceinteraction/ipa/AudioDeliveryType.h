///////////////////////////////////////////////////////////
//  AudioDeliveryType.h
//  Implementation of the Enumeration AudioDeliveryType
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_C8411B85_9B7F_4a80_BD05_97815CF258AD__INCLUDED_)
#define EA_C8411B85_9B7F_4a80_BD05_97815CF258AD__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * Type of audio delivery.
			 */
			enum AudioDeliveryType
			{
				/**
				 * The audio is delivered in a single chunk.
				 */
				Endpointed = 0,
				/**
				 * The audio is delivered in a stream.
				 */
				Streaming = 1
			};

		}

	}

}
#endif // !defined(EA_C8411B85_9B7F_4a80_BD05_97815CF258AD__INCLUDED_)