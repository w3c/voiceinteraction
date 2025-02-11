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
 * @brief A listener for multimodal input events.
 * 
 * This class provides an interface for handling multimodal input events.
 * Implementations of this class should define the behavior for processing
 * multimodal inputs and retrieving the next set of inputs.
 * 
 * @note This is an abstract class and cannot be instantiated directly.
 * 
 * @see MultiModalData
 * @see MultiModalDataCollection
 * 
 * @author Dirk Schnelle-Walka
 */
class CaptureModalityComponentListener  {
public:
    /**
     * @brief Constructs an InputModalityComponentListener object.
     */
    CaptureModalityComponentListener();

    /**
     * @brief Destroys the InputModalityComponentListener object.
     */
    virtual ~CaptureModalityComponentListener();

    /**
     * @brief Handles the provided multimodal input.
     * 
     * This method is called when the input modality component receives
     * a new multimodal input. Implementations should define the behavior
     * for processing the input.
     * 
     * @param input The multimodal input to be processed.
     */
    virtual void onMultiModalInput(std::shared_ptr<MultiModalData> input) = 0;

    /**
     * @brief Retrieves the next set of multimodal inputs.
     * 
     * This method blocks until the next set of multimodal inputs is available.
     * The conditions for returning from this method are determined by the
     * implementation.
     * 
     * @return A shared pointer to the next set of multimodal inputs.
     */
    virtual std::shared_ptr<MultiModalDataCollection> getMultiModalInputs() = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c


#endif // INPUTMODALITYCOMPONENTLISTENER_H
