#include "TextMultiModalInput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

const std::string TextMultiModalInput::MODALITY = std::string("text");

TextMultiModalInput::TextMultiModalInput(const std::string& output)
    : text(output) {
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
