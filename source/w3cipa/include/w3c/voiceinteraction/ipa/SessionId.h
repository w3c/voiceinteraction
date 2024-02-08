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

#if !defined(SESSION_ID)
#define SESSION_ID

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The SessionId interface is used to identify a session.
 * @author Dirk Schnelle-Walka
 */
class SessionId
{
public:
    /**
     * Constucts a new SessionId.
     */
    SessionId() {
    }

    /**
     * Destroys the SessionId.
     */
    virtual ~SessionId() {
    }

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(SESSION_ID)
