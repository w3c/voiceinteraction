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

#ifndef MULTIMODAL_CAPTURE_SYNCHRONISATTION_STRATEGY_H
#define MULTIMODAL_CAPTURE_SYNCHRONISATTION_STRATEGY_H

#include <memory>

#include "CaptureModalityComponentListener.h"
#include "InteractionManager.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace client {

/**
 * @brief A strategy to synchronize inputs from multiple modality components.
 * 
 * Implementations of this class should define the behavior for synchronizing in
 * the method {@link CaptureModalityComponentListener#onMultiModalInput(std::shared_ptr<MultiModalData>)}
 * and when synchronized, call {@link
 * #notifyInteractionManager(std::shared_ptr<MultiModalDataCollection>)}.
 * 
 * @note This class is part of the IPA Reference Implementation.
 * 
 * @see CaptureModalityComponentListener
 * @see MultiModalData
 * 
 * @author Dirk Schnelle-Walka
 */
class MulitModalCaptureSynchronisationStrategy : public CaptureModalityComponentListener {
public:
    /**
     * @brief Constructs a new MulitModalCaptureSynchronisationStrategy object.
     */
    MulitModalCaptureSynchronisationStrategy(
     const std::shared_ptr<InteractionManager>&
         im);

    /**
     * @brief Destroys the MulitModalCaptureSynchronisationStrategy object.
     */
    virtual ~MulitModalCaptureSynchronisationStrategy();

protected:
    /**
     * @brief Notifies the listener of the new multimodal input.
     * @param data The multimodal input to be processed.
     */
    void notifyInteractionManager(std::shared_ptr<MultiModalDataCollection>& data);

private:
    /** The interactionmanager to inform once there is multimodal input available. */
    std::shared_ptr<InteractionManager> interactionManager;
};

} // namespace client
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // MULTIMODAL_CAPTURE_SYNCHRONISATTION_STRATEGY_H
