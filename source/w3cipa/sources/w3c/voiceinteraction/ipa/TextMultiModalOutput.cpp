#include "TextModalityType.h"
#include "TextMultiModalOutput.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

const ModalityType TextMultiModalOutput::MODALITY = TextModalityType();

TextMultiModalOutput::TextMultiModalOutput(const std::string& output)
    : MultiModalOutput(MODALITY),
      text(output) {
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
