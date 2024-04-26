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

#include <list>

#include "w3c/voiceinteraction/ipa/ModalityType.h"
#include "w3c/voiceinteraction/ipa/client/IOType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A component to hand multimodal input or output.
 * @author Dirk Schnelle-Walka
 */
class ModalityComponent {
public:
    /**
     * Creates a object.
     * @param modality the supported modality.
     */
    ModalityComponent(const ModalityType& modality);

    /**
     * Destroys the object.
     */
    virtual ~ModalityComponent();

    /**
     * Retrieves a string identifying the modality of this input.
     */
    const ModalityType& getModality() const;

    /**
     * Retrieves a list IO type that are supported by this modality component.
     * @return the supported IO types of this modality component.
     */
    virtual const std::list<IOType> getSupportedIOTypes() const = 0;

private:
    /** The modality of this input. */
    ModalityType modality;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // MODALITYCOMPONENT_H
