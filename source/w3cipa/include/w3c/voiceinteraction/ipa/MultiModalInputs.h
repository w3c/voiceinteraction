/*
 * IPA Reference Implementation: https://github.com/w3c/voiceinteraction
 *
 * Copyright (C) 2024 World Wide Web Consortium. All Rights Reserved.
 *
 * This work is distributed under the W3C Software and Document License [1]
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] https://www.w3.org/Consortium/Legal/copyright-software
 */

#if !defined(MULTIMODALINPUTS_H)
#define MULTIMODALINPUTS_H

#include <memory>
#include <map>
#include <list>

#include "ModalityType.h"
#include "MultiModalInput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class contains a set of multimodal inputs.
 * @author Dirk Schnelle-Walka
 */
class MultiModalInputs
{

public:
    /**
     * Constructs an empty set of multimodal inputs.
     */
    MultiModalInputs() {
    }

    /**
     * Destroys the set of multimodal inputs.
     */
    virtual ~MultiModalInputs() {
    }

    /**
     * Adds a multimodal input to the set.
     * @param input The multimodal input to add.
     */
    void addMultiModalInput(const std::shared_ptr<MultiModalInput>& input) {
        const ModalityType& modality = input->getModality();
        inputs[modality] = input;
    }

    /**
     * Returns the multimodal input for the given modality.
     * @param modality The modality to return.
     * @return The multimodal input for the given modality, {@code nullptr} if
     *  the modality could not be found.
     */
    std::shared_ptr<MultiModalInput> getMultiModalInput(const ModalityType& modality) const {
        std::map<ModalityType, std::shared_ptr<MultiModalInput>>::const_iterator iterator =
            inputs.find(modality);
        if (iterator == inputs.end()) {
            return nullptr;
        }
        return iterator->second;
    }

    /**
     * Retrieves all modality types provided in this input.
     * @return list of all modality types
     */
    std::list<ModalityType> getInputModalities() const {
        std::list<ModalityType> types;
        for (std::map<ModalityType, std::shared_ptr<MultiModalInput>>::const_iterator iterator = inputs.begin();
             iterator != inputs.end(); ++iterator) {
            types.push_back(iterator->first);
        }
        return types;
    }
private:
    /**
     * The map of known multimodal inputs.
     */
    std::map<ModalityType, std::shared_ptr<MultiModalInput>> inputs;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MULTIMODALINPUTS_H)
