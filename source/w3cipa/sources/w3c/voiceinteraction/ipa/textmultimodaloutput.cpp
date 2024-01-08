#include "textmultimodaloutput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

const std::string TextMultiModalOutput::MODALITY = std::string("text");

TextMultiModalOutput::TextMultiModalOutput(const std::string& output)
    : text(output) {
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
