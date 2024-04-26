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

#ifndef UUIDSESSIONID_H
#define UUIDSESSIONID_H

#include <uuid.h>

#include <w3c/voiceinteraction/ipa/SessionId.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {

/**
 * A session identifier that uses a UUID.
 * @author Dirk Schnelle-Walka
 */
class UUIDSessionId : public SessionId
{
public:
    UUIDSessionId();

    UUIDSessionId(const UUIDSessionId& sessionId);

    /**
     * @brief operator =
     * @param other the other modality
     */
    void operator=(const UUIDSessionId& other);

    const std::string& toString() const override;

private:
    /** The UUID. */
    uuids::uuid id;

    /** String representation of the id. */
    std::string idString;
};

} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // UUIDSESSIONID_H
