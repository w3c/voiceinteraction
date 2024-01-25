///////////////////////////////////////////////////////////
//  MultiModalOutput.h
//  Implementation of the Interface MultiModalOutput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_)
#define EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_

#include <string>

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * This interface is used to represent the output of a modality.
			 */
			class MultiModalOutput
			{

			public:
				/**
				 * Constructs a new object.
				 */
				MultiModalOutput() {
				}

				/**
				 * Destroys the object.
				 */
				virtual ~MultiModalOutput() {
				}

				/**
				 * Returns the modality of this output.
				 */
                virtual const std::string getModality() const = 0;
			};

		}

	}

}
#endif // !defined(EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_)
