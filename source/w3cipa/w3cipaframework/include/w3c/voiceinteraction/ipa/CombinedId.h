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

#ifndef COMBINEDID_H
#define COMBINEDID_H

#include <memory>
#include <string>

#include "w3c/voiceinteraction/ipa/SessionId.h"
#include "w3c/voiceinteraction/ipa/RequestId.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Container class to capture a SessionId and a RequestId in a single instance,
 * e.g., to track callbacks. The request id may be null while the session id
 * is mandatory to have.
 * @author Dirk Schnelle-Walka
 */
class CombinedId {
public:
    /**
     * Creates a new object.
     * @param session the session identifier
     * @param request the request identifier
     */
    CombinedId(const std::shared_ptr<SessionId>& session,
               const std::shared_ptr<RequestId>& request);

    /**
     * Creates a new object as a copy of the provided object.
     * @param id the object to copy from
     */
    CombinedId(const CombinedId& id);

    /**
     * Destroys this instance.
     */
    virtual ~CombinedId();

    /**
     * Retrieves the session id.
     * @return the session id
     */
    const std::shared_ptr<SessionId>& getSessionId() const;

    /**
     * Retrieves the request id.
     * @return the request id
     */
    const std::shared_ptr<RequestId> &getRequestId() const;

    /**
     * Returns a string representation of the combined ids in the form
     * {@code sessionId.toString()[::requestId.toString()]}.
     * @return string representation
     */
    const std::string& toString() const;

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other session identifier
     * @return {@code true} in case the
     *          {@code toString() < other.toString()}.
     */
    bool operator<(const CombinedId& other) const;

    /**
     * @brief operator ==
     * @param other the other combined identifier
     * @return {@code true} in case the
     *          {@code toString() == other.toString()}.
     */
    bool operator==(const CombinedId& other) const;

    /**
     * @brief operator =
     * @param other the other combined identifier
     */
    CombinedId& operator=(const CombinedId& other);
private:
    /** The encapuslated session id. */
    std::shared_ptr<SessionId> sessionId;
    /** The encapsulated request id. */
    std::shared_ptr<RequestId> requestId;
    /** String representation of this object. */
    std::string combinedId;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // COMBINEDID_H
