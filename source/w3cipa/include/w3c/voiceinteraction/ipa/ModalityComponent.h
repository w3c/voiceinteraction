#ifndef MODALITYCOMPONENT_H
#define MODALITYCOMPONENT_H

#include <memory>

#include "ModalityType.h"
#include "IOType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * A compponent to hand mutlimodal input or output.
 */
class ModalityComponent {
public:
	/**
	 * Creates a object.
	 * @param modality the supported modality.
	 */
	 */
	ModalityComponent(modality)
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

	/**
	 * Retrieves the IO type of this modality component.
	 * @return the IO type of this modality component.
	 */
	 */
	virtual const getIOType() const = 0;
private:
	/**
	 * The modality of this input.
	 */
	ModalityType modality;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // MODALITYCOMPONENT_H
