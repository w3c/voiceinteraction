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

#ifndef VOICEMODALITYTYPE_H
#define VOICEMODALITYTYPE_H

#include <w3c/voiceinteraction/ipa/ModalityType.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The voice modality type.
 * @author Dirk Schnelle-Walka
 */
class VoiceModalityType : public ModalityType
{
public:
    /**
     * Constructs a new object.
     */
    VoiceModalityType();

    /**
     * Copy constructor.
     * @param other the object to copy from
     */
    VoiceModalityType(const VoiceModalityType& other);
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // VOICEMODALITYTYPE_H
