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

#ifndef INPUTMODALITYCOMPONENTLISTENER_H
#define INPUTMODALITYCOMPONENTLISTENER_H

#include <memory>

#include "w3c/voiceinteraction/ipa/MultiModalDataCollection.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A listener for multimodal input events
 * @author Dirk Schnelle-Walka
 */
class InputModalityComponentListener {
public:
    /**
     * Creates a object.
     */
    InputModalityComponentListener();

    /**
     * @brief Destroy this object.
     */
    virtual ~InputModalityComponentListener();

    /**
     * The input modality component received the provided multimodal input.
     * @param input the multimodal input.
     */
    virtual void onMultiModalInput(std::shared_ptr<MultiModalData> input) = 0;

    /**
     * Obtains the next input for the IPA. This call is blocking until input
     * is available. It is up to the implementation to decide upon the
     * conditions when this method returns.
     * @return next input for the IPA
     */
    virtual std::shared_ptr<MultiModalDataCollection> getMultiModalInputs() = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c


#endif // INPUTMODALITYCOMPONENTLISTENER_H
