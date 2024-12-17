/*
 * IPA Reference Implementation: https://github.com/w3c/voiceinteraction
 *
 * Copyright (C) 2024 World Wide Web Consortium. All Rights Reserved.
 *
 * This work is distributed under the W3C Software and Document License [1]
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [1] https://www.w3.org/Consortium/Legal/copyright-software
 */
#ifndef TEXTMULTIMODALINPUT_H
#define TEXTMULTIMODALINPUT_H

#include <string>

#include <w3c/voiceinteraction/ipa/LanguageDependent.h>
#include <w3c/voiceinteraction/ipa/MultiModalData.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {

/**
 * @brief A multimodal output for text.
 * @author Dirk Schnelle-Walka
 */
class TextMultiModalInput 
    : public MultiModalData, public LanguageDependent {
public:
    /**
     * Constructs a new object.
     * @param input the text
     * @param lang the language of the text, defaults to EN
     */
    TextMultiModalInput(const std::string& input, const Language& lang = Language::EN);

    /**
     * Returns the text.
     * @return the text
     */
    const std::string& getText() const {
        return text;
    }

    const Language& getLanguage() const override {
        return language;
    }

    const static ModalityType MODALITY;
private:
    /** The text. */ 
    std::string text;
    /** The language of the text. */
    Language language;
};

} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMULTIMODALINPUT_H
