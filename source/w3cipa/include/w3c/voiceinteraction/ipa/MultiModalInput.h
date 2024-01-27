///////////////////////////////////////////////////////////
//  MultiModalInput.h
//  Implementation of the Interface MultiModalInput
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_)
#define EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_

#include <string>

#include "ModalityType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to represent input from a modality.
 */
class MultiModalInput
{

public:
	/**
	 * Constructs a new object.
	 * @param modality The modality of this input.
	 */
	MultiModalInput(const ModalityType modality)
		: modality(modality) {
	}

	/**
	 * Destroys the object.
	 */
	virtual ~MultiModalInput() {

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

#endif // !defined(EA_D4083AFB_7D40_4225_A755_EEF04D2E5A2E__INCLUDED_)
