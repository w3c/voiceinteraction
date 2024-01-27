#ifndef TEXTMODALITYTYPE_H
#define TEXTMODALITYTYPE_H

#include <w3c/voiceinteraction/ipa/ModalityType.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The text modality type.
 */
class TextModalityType : public ModalityType
{
public:
    TextModalityType();
    TextModalityType(const TextModalityType& other);
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TEXTMODALITYTYPE_H
