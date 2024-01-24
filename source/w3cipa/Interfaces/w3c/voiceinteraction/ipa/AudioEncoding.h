///////////////////////////////////////////////////////////
//  AudioEncoding.h
//  Implementation of the Interface AudioEncoding
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_03EBBAEA_11EE_446d_8DFF_6F98152CABCF__INCLUDED_)
#define EA_03EBBAEA_11EE_446d_8DFF_6F98152CABCF__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * The AudioEncoding interface represents the encoding of an audio stream.
			 */
			class AudioEncoding
			{
			public:
				/**
				 * Constructs a new object.
				 */
				AudioEncoding() {
				}

				/**
				 * Destroys this object.
				 */
				virtual ~AudioEncoding() {
				}

			};

		}

	}

}
#endif // !defined(EA_03EBBAEA_11EE_446d_8DFF_6F98152CABCF__INCLUDED_)
