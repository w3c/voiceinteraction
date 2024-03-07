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

#if !defined(AUDIODATA_H)
#define AUDIODATA_H

#include "AudioDeliveryType.h"
#include "AudioEncoding.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Base class for all audio data types.
 * @author Dirk Schnelle-Walka
 */
class AudioData
{

public:
    /**
     * Constructs a new object.
     */
    AudioData() {
    }

    /**
     * Destroys the object.
     */
    virtual ~AudioData() {
    }

    /**
     * Retrieves the audio delivery type of this audio data object.
     */
    virtual AudioDeliveryType getAudioDeliveryType() = 0;

    /**
     * Retrieves the audio encoding of this audio data object.
     */
    virtual const AudioEncoding& getEncoding() = 0;

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(AUDIODATA_H)
