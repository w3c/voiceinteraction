#ifndef TEXTMULTIMODALINPUT_H
#define TEXTMULTIMODALINPUT_H

#include <string>

#include <w3c/voiceinteraction/ipa/MultiModalInput.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

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
