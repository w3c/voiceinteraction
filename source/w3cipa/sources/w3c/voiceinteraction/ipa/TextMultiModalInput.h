﻿/*
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

#include <w3c/voiceinteraction/ipa/MultiModalInput.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * @brief A multimodal output for text.
 * @author Dirk Schnelle-Walka
 */
class TextMultiModalInput : public MultiModalInput {
public:
    TextMultiModalInput(const std::string& input);

    const std::string& getTextInput() const {
        return text;
    }

    const static ModalityType MODALITY;
private:
    std::string text;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMULTIMODALINPUT_H
