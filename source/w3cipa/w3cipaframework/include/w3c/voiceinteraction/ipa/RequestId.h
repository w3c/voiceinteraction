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

#if !defined(REQUEST_ID_H)
#define REQUEST_ID_H

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The request id is used to identify a request within a session. It can used to
 * match a request with a response.
 * @author Dirk Schnelle-Walka
 */
class RequestId
{

public:
    /**
     * Constructs a new request id.
     */
    RequestId() {
    }

    /**
     * Destroys the request id.
     */
    virtual ~RequestId() {
    }

    /**
     * Creates a human readable representation of this request id.
     * @return request identifier as a string
     */
    virtual const std::string& toString() const = 0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(REQUEST_ID_H)
