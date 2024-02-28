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

#if !defined(SEMANTI_INTERPRETATION_H)
#define SEMANTI_INTERPRETATION_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Semantic interpretation of an utterance.
 * @author Dirk Schnelle-Walka
 */
class SemanticInterpretation
{

public:
    /**
     * Constructs a new request id.
     */
    SemanticInterpretation() {
    }

    /**
     * Destroys the request id.
     */
    virtual ~SemanticInterpretation() {
    }

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(SEMANTI_INTERPRETATION_H)
