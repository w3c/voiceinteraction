#include "TextModalityType.h"
#include "TextMultiModalInput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

const ModalityType TextMultiModalInput::MODALITY = TextModalityType();

TextMultiModalInput::TextMultiModalInput(const std::string& input)
    : MultiModalInput(MODALITY),
      text(input) {
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
