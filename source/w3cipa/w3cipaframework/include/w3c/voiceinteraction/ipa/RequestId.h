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
 * @brief Represents a unique request identifier within a session.
 * 
 * The request id is used to uniquely identify a request within a session. It
 * can be used to
 * match a request with its corresponding response.
 * 
 * This class provides methods to create, compare, and represent request identifiers.
 * @details The RequestId class is designed to be used in scenarios where requests need to be
 * uniquely identified and matched with their corresponding responses. It supports comparison
 * operations to facilitate its use in standard containers like std::map.
 * 
 * @note This class is abstract and must be derived to provide a concrete implementation of
 * the toString() method.
 * 
 * @see std::map
 * @author Dirk Schnelle-Walka
 */
class RequestId
{

public:
    /**
     * Constructs a new request id.
     */
    RequestId();

    /**
     * Destroys the request id.
     */
    virtual ~RequestId();

    /**
     * Creates a human readable representation of this request id.
     * @return request identifier as a string
     */
    virtual const std::string& toString() const = 0;

    /**
     * @brief operator <
     * Comparison to allow for usage in {@code std::map}s.
     * @param other the other session identifier
     * @return {@code true} in case the
     *          {@code toString() < other.toString()}.
     */
    bool operator<(const RequestId& other) const;

    /**
     * @brief operator ==
     * @param other the other session identifier
     * @return {@code true} in case the
     *          {@code toString() == other.toString()}.
     */
    bool operator==(const RequestId& other) const;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(REQUEST_ID_H)
