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

#if !defined(MULTI_MODAL_INPUT_H)
#define MULTI_MODAL_INPUT_H

#include "ModalityType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to represent input from a modality.
 * @author Dirk Schnelle-Walka
 */
class MultiModalInput
{

public:
    /**
     * Constructs a new object.
     * @param modality The modality of this input.
     */
    MultiModalInput(const ModalityType modality);

    /**
     * Destroys the object.
     */
    virtual ~MultiModalInput();

    /**
     * Retrieves a string identifying the modality of this input.
     */
    const ModalityType& getModality() const;

private:
    /**
     * The modality of this input.
     */
    ModalityType modality;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(MULTI_MODAL_INPUT_H)
