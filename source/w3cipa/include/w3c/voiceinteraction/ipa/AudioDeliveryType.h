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

#if !defined(AUDIODELIVERYTYPE_H)
#define AUDIODELIVERYTYPE_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Type of audio delivery.
 * @author Dirk Schnelle-Walka
 */
enum AudioDeliveryType
{
    /**
     * The audio is delivered in a single chunk.
     */
    Endpointed = 0,
    /**
     * The audio is delivered in a stream.
     */
    Streaming = 1
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EA_C8411B85_9B7F_4a80_BD05_97815CF258AD__INCLUDED_)
