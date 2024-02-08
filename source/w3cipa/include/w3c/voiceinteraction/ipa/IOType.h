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

#if !defined(IOTYPE_H)
#define IOTYPE_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {
/**
 * Type of input or output of a {@link ModalityComponent}.
 * @author Dirk Schnelle-Walka
 */
enum IOType
{
    /**
     * The component is an input device.
     */
    INPUT = 0,
    /**
     * Teh component is an output device.
     */
    OUTPUT = 1
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(IOTYPE_H)
