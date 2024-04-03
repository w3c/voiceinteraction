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

#if !defined(CALL_RESULT_H)
#define CALL_RESULT_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Indicator to success or failure.
 * @author Dirk Schnelle-Walka
 */
enum CallResult
{
    /**
     * A call has been completed successfully.
     */
    SUCCESS = 0,
    /**
     * There was an error in the call.
     */
    FAILURE = 1
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(CALL_RESULT_H)
