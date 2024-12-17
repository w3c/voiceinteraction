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

#if !defined(TIMESTAMP_H)
#define TIMESTAMP_H

#include <string>
#include <ctime>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * A timestamp is a point in time.
 * @author Dirk Schnelle-Walka
 */
class Timestamp {

public:
    /**
     * Constructs a new object.
     */
    Timestamp();

    /**
     * Copy constructor.
     * @param other the object to copy
     */
    Timestamp(const Timestamp& other) = default;

    /**
     * Destroys the object.
     */
    virtual ~Timestamp();

    /**
     * Returns a string representation in ISO 8601 format of the timestamp.
     * @return the string representation
     */
    const std::string & toString() const;

private:
    /** The timestamp. */
    std::time_t timestamp;
    /** The string representation of the timestamp. */
    std::string iso8601;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(TIMESTAMP_H)
