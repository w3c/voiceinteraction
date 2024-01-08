#ifndef TEXTMULTMODALOUTPUT_H
#define TEXTMULTMODALOUTPUT_H

#include <string>

#include <w3c/voiceinteraction/ipa/MultiModalOutput.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

class TextMultiModalOutput : public MultiModalOutput {
public:
    TextMultiModalOutput(const std::string& output);

    virtual const std::string getModality() const {
        return MODALITY;
    };

    const std::string& getTextOutput() const {
        return text;
    }

    const static std::string MODALITY;
private:
    std::string text;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMULTMODALOUTPUT_H
