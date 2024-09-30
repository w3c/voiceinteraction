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
#include "Language.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class contains a set of multimodal inputs. This implementation
 * allows for only on input per modality.
 * @author Dirk Schnelle-Walka
 */
class MultiModalInputs
{

public:
    /**
     * Constructs an empty set of multimodal inputs.
     */
    MultiModalInputs();

    /**
     * Destroys the set of multimodal inputs.
     */
    virtual ~MultiModalInputs();

    /**
     * Adds a multimodal input to the set. An existing entry for the
     * provided modality will be overwritten.
     * @param input The multimodal input to add.
     */
    void addMultiModalInput(const std::shared_ptr<MultiModalInput>& input);

    /**
     * Returns the multimodal input for the given modality.
     * @param modality The modality to return.
     * @return The multimodal input for the given modality, {@code nullptr} if
     *  the modality could not be found.
     */
    std::shared_ptr<MultiModalInput> getMultiModalInput(const ModalityType& modality) const;

    /**
     * Retrieves all modality types provided in this input.
     * @return list of all modality types
     */
    std::list<ModalityType> getInputModalities() const;

    /**
     * Retrieves all languages supported by the input.
     * @return list of all supported languages
     */
    std::list<Language> getInputLanguages() const;

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
