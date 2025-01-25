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

#include <memory>

#include "RequestId.h"
#include "SessionId.h"

#ifndef IPADATA_H
#define IPADATA_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief Base class for all data that is sent around through various processing stages.
 * 
 * This class serves as a base for all data types that are transmitted through different stages of
   processing within the voice interaction framework. It
 * contains a {@link SessionId} and an optional a {@link requestId} to allow for a separationg
 * different requests.
 * 
 * @note This class is intended to be subclassed to provide specific data implementations.
 * 
 * @see SessionId
 * @see RequestId
 * 
 * @author Dirk Schnelle-Walka
 */
class IPAData {
public:
    /**
     * @brief Constructs a new IPAData object with a session identifier and an optional request identifier.
     * 
     * @param sessionIdentifier The session identifier.
     * @param requestIdentifier The request identifier, may be {@code nullptr}.
     */
    IPAData(const std::shared_ptr<SessionId>& sessionIdentifier,
            const std::shared_ptr<RequestId>& requestIdentifier);

    /**
     * @brief Constructs a new IPAData object with a session identifier.
     * 
     * @param sessionIdentifier The session identifier.
     */
    IPAData(const std::shared_ptr<SessionId>& sessionIdentifier);

    /**
     * @brief Destroys the IPAData object.
     */
    virtual ~IPAData();

    /**
     * @brief Returns the session id of the session this response belongs to.
     * 
     * @return The session id of the session this response belongs to.
     */
    const std::shared_ptr<SessionId>& getSessionId() const;

    /**
     * @brief Sets the session identifier.
     * 
     * @param sessionIdentifier The new session identifier.
     */
    void setSessionId(const std::shared_ptr<SessionId>& sessionIdentifier);

    /**
     * @brief Returns the request id of the request this response belongs to.
     * 
     * @return The request id of the request this response belongs to.
     */
    const std::shared_ptr<RequestId>& getRequestId() const;

private:
    /** The session id. */
    std::shared_ptr<SessionId> sessionId;
    /** The request id. */
    std::shared_ptr<RequestId> requestId;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // IPADATA_H
