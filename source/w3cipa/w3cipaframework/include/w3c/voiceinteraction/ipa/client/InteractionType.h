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

#if !defined(INTERACTION_TYPE_H)
#define INTERACTION_TYPE_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief Enum representing the type of input or output of a {@link ModalityComponent}.
 * 
 * This enum is used to specify whether a component is an capture device or a presentation device or both.
 * 
 * @author Dirk Schnelle-Walka
 */
enum InteractionType
{
    /**
     * The component is an input device.
     */
    CAPTURE = 0,
    /**
     * The component is an output device.
     */
    PRESENTATION = 1
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(INTERACTION_TYPE_H)
