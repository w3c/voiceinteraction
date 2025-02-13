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

#ifndef PRESENTATION_MODALITYCOMPONENT_H
#define PRESENTATION_MODALITYCOMPONENT_H

#include <memory>

#include "w3c/voiceinteraction/ipa/MultiModalData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * A component to hand mutlimodal outputs and present it to the user.
 *
 * Output modality components are also asked to inherit from
 * {@link ModalityComponent} and support {@link IOType::OUTPUT}.
 *
 * @author Dirk Schnelle-Walka
 */
/**
 * A component to handle multimodal outputs.
 *
 * Output modality components are also required to inherit from
 * {@link ModalityComponent} and support {@link InteractionType#PRESENTATION}.
 *
 * @brief This class handles the output modality in a multimodal interaction system.
 * 
 * @details The OutputModalityComponent class is responsible for processing and managing
 * multimodal outputs. It serves as an interface for handling different types of output
 * modalities in a voice interaction system.
 *
 * @note Implementations of this class must provide the handleOutput method to process
 * the obtained multimodal output.
 *
 * @author Dirk Schnelle-Walka
 */
class PresentationModalityComponent {
public:
    /**
     * @brief Constructs an OutputModalityComponent object.
     */
    PresentationModalityComponent();

    /**
     * @brief Destroys this object.
     */
    virtual ~PresentationModalityComponent();

    /**
     * @brief Handles the obtained multimodal output for presentation.
     * 
     * @param output The obtained output.
     */
    virtual void present(
            const std::shared_ptr<MultiModalData>& output) = 0;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // PRESENTATION_MODALITYCOMPONENT_H
