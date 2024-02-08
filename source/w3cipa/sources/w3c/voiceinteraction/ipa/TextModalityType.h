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

#ifndef TEXTMODALITYTYPE_H
#define TEXTMODALITYTYPE_H

#include <w3c/voiceinteraction/ipa/ModalityType.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The text modality type.
 * @author Dirk Schnelle-Walka
 */
class TextModalityType : public ModalityType
{
public:
    TextModalityType();
    TextModalityType(const TextModalityType& other);
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMODALITYTYPE_H
