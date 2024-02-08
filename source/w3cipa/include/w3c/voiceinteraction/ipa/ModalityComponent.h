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

#ifndef MODALITYCOMPONENT_H
#define MODALITYCOMPONENT_H

#include "ModalityType.h"
#include "IOType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * A compponent to hand mutlimodal input or output.
 * @author Dirk Schnelle-Walka
 */
class ModalityComponent {
public:
    /**
     * Creates a object.
     * @param modality the supported modality.
     */
    ModalityComponent(const ModalityType& modality)
        : modality(modality) {
    }

    /**
     * Destroys the object.
     */
    virtual ~ModalityComponent() {

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
    virtual const IOType getIOType() const = 0;
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
