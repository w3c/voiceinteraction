///////////////////////////////////////////////////////////
//  MultiModalInput.h
//  Implementation of the Interface MultiModalInput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_)
#define EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_

#include <string>

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * This interface is used to represent input from a modality.
			 */
			class MultiModalInput
			{

			public:
				/**
				 * Constructs a new object.
				 */
				MultiModalInput() {
				}

				/**
				 * Destroys the object.
				 */
				virtual ~MultiModalInput() {

				}

				/**
				 * Retrieves a string identifying the modality of this input.
				 */
                virtual const std::string getModality() const = 0;
			};

		}

	}

}
#endif // !defined(EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_)
