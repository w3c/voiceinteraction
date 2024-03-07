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

#ifndef TEXTMULTMODALOUTPUT_H
#define TEXTMULTMODALOUTPUT_H

#include <string>

#include <w3c/voiceinteraction/ipa/MultiModalOutput.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {

/**
 * @brief Multimodal output for text.
 * @author Dirk Schnelle-Walka
 */
class TextMultiModalOutput : public MultiModalOutput {
public:
    TextMultiModalOutput(const std::string& output);

    const std::string& getTextOutput() const {
        return text;
    }

    const static ModalityType MODALITY;
private:
    std::string text;
};

} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMULTMODALOUTPUT_H
