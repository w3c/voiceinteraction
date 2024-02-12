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

#if !defined(MULTIMODALOUTPUTS_H)
#define MULTIMODALOUTPUTS_H

#include <memory>
#include <list>
#include <map>

#include "ModalityType.h"
#include "MultiModalOutput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class represents a set of multi modal outputs.
 * @author Dirk Schnelle-Walka
 */
class MultiModalOutputs
{

public:
    /**
     * Constructs an empty set of multi modal outputs.
     */
    MultiModalOutputs() {
    }

    /**
     * Destroys the set of multi modal outputs.
     */
    virtual ~MultiModalOutputs() {
    }

    /**
     * Adds a multi modal output to the set.
     * @param output The multi modal output to add.
     */
    void addMultiModalOutput(const std::shared_ptr<MultiModalOutput> output) {
        const ModalityType& modality = output->getModality();
        outputs[modality] = output;
    }

    /**
     * Returns the multi modal output for the given modality.
     * @param modality The modality to get the multi modal output for.
     * @return The multi modal output for the given modality.
     */
    std::shared_ptr<MultiModalOutput> getMultiModalOutput(
        const ModalityType& modality) {
        return outputs[modality];
    }

    /**
     * Retrieves all known modality types.
     * @return known modality types
     */
    std::list<ModalityType> getModalityTypes() const {
        std::list<ModalityType> types;
        for (std::map<ModalityType, std::shared_ptr<MultiModalOutput>>::const_iterator iterator = outputs.begin();
             iterator != outputs.end(); ++iterator) {
            const ModalityType type = iterator->first;
            types.push_back(type);
        }
        return types;
    }
private:
    /**
     * The map of known multi modal outputs.
     */
    std::map<ModalityType, std::shared_ptr<MultiModalOutput>> outputs;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MULTIMODALOUTPUTS_H)
