﻿/*
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

#ifndef TEXTMODALITYTYPE_H
#define TEXTMODALITYTYPE_H

#include <w3c/voiceinteraction/ipa/ModalityType.h>

#include <w3cipaframework_export.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The text modality type.
 * @author Dirk Schnelle-Walka
 */
class TextModalityType : public ModalityType {
 public:
    /**
     * Constructs a new object.
     */
    TextModalityType();

    /**
     * Copy constructor.
     * @param other the object to copy from
     */
    TextModalityType(const TextModalityType& other);

    /**
     * Retrieves an instance of this modality type.
     * @return an instance
     */
    static TextModalityType getInstance();
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMODALITYTYPE_H
