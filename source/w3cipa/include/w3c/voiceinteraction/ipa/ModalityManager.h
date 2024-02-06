#if !defined(MODALITYMANAGER_H)
#define MODALITYMANAGER_H

#include <memory>
#include <map>

#include "ModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * A component that manages multiple modalities..
 */
class ModalityManager
{

public:
	/**
	 * Constructs a new object.
	 */
	ModalityManager() {
	}

	/**
	 * Destroys the object.
	 */
	virtual ~ModalityManager() {
	}

	/**
	 * Adds a modality component to the set of modality components.
	 * @param component The modality component to add to the set of modality
	 * 			components.
	 */
	void addModalityComponent(
			const std::shared_ptr<ModalityComponent> component) {
		const ModalityType& modality = component->getModality();
		const IOType& ioType = component->getIOType();
		if (ioType == IOType::INPUT) {
			inputComponents[modality] = component;
		} else {
			outputComponents[modality] = component;
		}
	}

	/**
	 * Gets the modality component for the specified modality.
	 * @param modality The modality for which to get the modality component.
	 * @param ioType The IOType for which to get the modality component.
	 * @return The modality component for the specified modality.
	 */
	std::shared_ptr<MultiModalOutput> getModalityComponent(
			const Modality& modality, const IOType& ioType) {
		if (ioType == IOType::INPUT) {
			return inputComponents[modality];
		} else {
			return outputComponents[modality];
		}
	}
private:
	/**
	 * The map of known input modality components.
	 */
	std::map<ModalityType, std::shared_ptr<component>> inputComponents;
	/**
	 * The map of known output modality components.
	 */
	std::map<ModalityType, std::shared_ptr<component>> outputComponents;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MODALITYMANAGER_H)
