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

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief The SessionId interface is used to identify a session.
 *
 * Dialog execution can be governed by a sessions, e.g. to free resources of
 * ASR and NLU engines when a session expires. Linguistic phenomena, like
 * anaphoric references and ellipsis, are expected to work within a session. The
 * selected IPA Providers or the Dialog Manager may have leading roles for this
 * task.
 *
 * @author Dirk Schnelle-Walka
 */
class SessionId
{
public:
    /**
     * Constucts a new SessionId.
     */
    SessionId();

    /**
     * Destroys the SessionId.
     */
    virtual ~SessionId();

    /**
     * Creates a human readable representation of this session id.
     * @return session identifier as a string
     */
    virtual const std::string& toString() const = 0;

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other session identifier
     * @return {@code true} in case the
     *          {@code toString() < other.toString()}.
     */
    bool operator<(const SessionId& other) const;

    /**
     * @brief operator ==
     * @param other the other session identifier
     * @return {@code true} in case the
     *          {@code toString() == other.toString()}.
     */
    bool operator==(const SessionId& other) const;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(SESSION_ID)
