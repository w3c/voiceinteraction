#ifndef INPUTMODALITYCOMPONENT_H
#define INPUTMODALITYCOMPONENT_H

#include <memory>

#include "ModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * A compponent to hand mutlimodal inputs
 */
class InputModalityComponent : public ModalityComponent {
public:
	/**
	 * Creates a object.
	 * @param modality the supported modality.
	 */
	 */
	 InputModalityComponent(modality)
		: modality(modality) {
	}

	/**
	 * Retrieves the IO type of this modality component.
	 * @return {@link IOType#INPUT}.
	 */
	 */
	virtual const getIOType() const {
		 return IOType::INPUT;
	}

	/**
	 * Obtains some multimodal input from this input modality component.
	 * @return the multimodal input.
	 */
	virtual const std::shared_ptr<MultiModalInput> getMultiModalInput() = 0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // INPUTMODALITYCOMPONENT_H
