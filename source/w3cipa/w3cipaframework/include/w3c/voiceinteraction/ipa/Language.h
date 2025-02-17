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

#include <w3cipaframework_export.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief This class implements a RFC 1766 language tag.
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
    Language(const std::string& primary, const std::string& sub = "");

    /**
     * Copy constructor.
     * @param other the object to copy
     */ 
    Language(const Language& other) = default;

    /**
     * Destroys the object.
     */
    virtual ~Language();

    /**
     * Returns a string representation of the language.
     * @return the string representation
     */
    std::string toString() const;

    /**
     * Checks if this lnaguage is equal to another one.
     * @param other the other language to compare
     */
    bool operator==(const Language & other) const;

    /** Language German */
    W3CIPAFRAMEWORK_EXPORT static const Language DE;
    /** Language English */
    W3CIPAFRAMEWORK_EXPORT static const Language EN;
    /** Language Spanish */
    W3CIPAFRAMEWORK_EXPORT static const Language ES;
    /** Language French */
    W3CIPAFRAMEWORK_EXPORT static const Language FR;
    /** Language Italian */
    W3CIPAFRAMEWORK_EXPORT static const Language IT;
    /** Language Japanese  */
    W3CIPAFRAMEWORK_EXPORT static const Language JA;
    /** Language Korean */
    W3CIPAFRAMEWORK_EXPORT static const Language KO;
    /** Language Dutch */
    W3CIPAFRAMEWORK_EXPORT static const Language NL;
    /** Language Polish */
    W3CIPAFRAMEWORK_EXPORT static const Language PL;
    /** Language Portuguese */
    W3CIPAFRAMEWORK_EXPORT static const Language PT;
    /** Language Russian */
    W3CIPAFRAMEWORK_EXPORT static const Language RU;
    /** Language Chinese */
    W3CIPAFRAMEWORK_EXPORT static const Language ZH;
    
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

