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

#if !defined(LANGUAGE_DEPENDENT_H)
#define LANGLANGUAGE_HUAGE_H

#include "Language.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This class is used to define language dependent data,
 * e.g., text or audio data in a specific language.
 * @author Dirk Schnelle-Walka
 */
class LanguageDependent {
    /**
        * Returns the claimed language of the data.
        * @return the language
        */
    virtual const Language& getLanguage() const = 0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // LANGUAGE_DEPENDENT_H

