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

    virtual const std::string getModality() const {
        return MODALITY;
    };

    const std::string& getTextInput() const {
        return text;
    }

    const static std::string MODALITY;
private:
    std::string text;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMULTIMODALINPUT_H
