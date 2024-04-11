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
 * Base class for all data that is sent around through various processing
 * stages.
 * @author Dirk Schnelle-Walka
 */
class IPAData {
public:
    /**
     * Constructs a new object.
     * @param sessionIdentifier the session identifier
     * @param requestIdentifier the request identifier, maybe {@code nullptr}
     */
    IPAData(const std::shared_ptr<SessionId>& sessionIdentifier,
            const std::shared_ptr<RequestId>& requestIdentifier);

    /**
     * Constructs a new object.
     * @param sessionIdentifier the session identifier
     */
    IPAData(const std::shared_ptr<SessionId>& sessionIdentifier);

    /**
     * Destroy this instance.
     */
    virtual ~IPAData();

    /**
     * Returns the session id of the session this response belongs to.
     * @return The session id of the session this response belongs to.
     */
    const std::shared_ptr<SessionId>& getSessionId() const;

    /**
     * Sets the session identifier.
     * @param sessionIdentifier the new session identifier
     */
    void setSessionId(const std::shared_ptr<SessionId>& sessionIdentifier);

    /**
     * Returns the request id of the request this response belongs to.
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
