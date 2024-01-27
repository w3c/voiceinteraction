///////////////////////////////////////////////////////////
//  MultiModalOutput.h
//  Implementation of the Interface MultiModalOutput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_)
#define EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_

#include <string>

#include "ModalityType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to represent the output of a modality.
 */
class MultiModalOutput
{

public:
	/**
	 * Constructs a new object.
	 * @param modality The modality of this input.
	 */
	MultiModalOutput(const ModalityType& modality)
		: modality(modality) {
	}

	/**
	 * Destroys the object.
	 */
	virtual ~MultiModalOutput() {
	}

	/**
	 * Retrieves a string identifying the modality of this input.
	 */
	const ModalityType& getModality() const {
		return modality;
	}

private:
	/**
	 * The modality of this input.
	 */
	ModalityType modality;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EA_FDD12529_7D17_4eb4_9E7A_D5CDE344613C__INCLUDED_)
