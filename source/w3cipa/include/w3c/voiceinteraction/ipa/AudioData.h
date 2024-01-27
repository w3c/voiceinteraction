///////////////////////////////////////////////////////////
//  AudioData.h
//  Implementation of the Interface AudioData
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_)
#define EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_

#include "AudioDeliveryType.h"
#include "AudioEncoding.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * Base class for all audio data types.
			 */
			class AudioData
			{

			public:
				/**
				 * Constructs a new object.
				 */
				AudioData() {
				}

				/**
				 * Destroys the object.
				 */
				virtual ~AudioData() {
				}

				/**
				 * Retrieves the audio delivery type of this audio data object.
				 */
				virtual AudioDeliveryType getAudioDeliveryType() = 0;

				/**
				 * Retrieves the audio encoding of this audio data object.
				 */
				virtual const AudioEncoding& getEncoding() = 0;

			};

		}

	}

}
#endif // !defined(EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_)
