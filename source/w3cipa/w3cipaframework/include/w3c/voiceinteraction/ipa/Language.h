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

#if !defined(LANGUAGE_H)
#define LANGUAGE_H

#include <string>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class implements a RFC 1766 language tag.
 *
 * A language describes a language and consists of a primary tag
 * and a subtags. Usually, the primary tag conforms to an ISO 639
 * language code and the first subtag conforms to an ISO 3166
 * country code. For the details, please refer to RFC 1766.
 *
 * In a string representation, primary and subtags are separated
 * by '-', e.g., "en-US" or "de-DE".
 * @author Dirk Schnelle-Walka
 */
class Language {

public:
    /**
     * Constucts a new object.
     * @param primary the primary tag
     * @param sub the sub tag
     */
    Language(const std::string& primary, const std::string& sub);

    /**
     * Destroys the object.
     */
    virtual ~Language();

    /**
     * Returns a string representation of the language.
     * @return the string representation
     */
    std::string toString() const;
private:
    /** The primary tag. */
    std::string primaryTag;
    /** The sub tag */
    std::string subTag;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(LANGUAGE_H)

