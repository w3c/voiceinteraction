///////////////////////////////////////////////////////////
//  AudioData.h
//  Implementation of the Interface AudioData
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_)
#define EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			class AudioData
			{

			public:
				AudioData() {

				}

				virtual ~AudioData() {

				}

				virtual w3c::voiceinteraction::ipa::AudioDeliveryType getAudioDeliveryType() =0;
				virtual const AudioEncoding& getEncoding() =0;

			};

		}

	}

}
#endif // !defined(EA_C9A6027B_742F_4f41_8BBD_1F4DB2B672B3__INCLUDED_)
