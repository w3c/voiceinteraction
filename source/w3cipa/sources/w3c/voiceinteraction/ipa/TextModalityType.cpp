#include "TextModalityType.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

TextModalityType::TextModalityType()
    : ModalityType("text") {
}

TextModalityType::TextModalityType(const TextModalityType& other)
    : ModalityType(other) {
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
