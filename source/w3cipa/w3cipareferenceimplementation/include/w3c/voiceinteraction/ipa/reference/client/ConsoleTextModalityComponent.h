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

#ifndef CONSOLETEXTMODALITYCOMPONENT_H
#define CONSOLETEXTMODALITYCOMPONENT_H

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/client/ModalityComponent.h>
#include <w3c/voiceinteraction/ipa/client/CaptureModalityComponent.h>
#include <w3c/voiceinteraction/ipa/client/MulitModalCaptureSynchronisationStrategy.h>
#include <w3c/voiceinteraction/ipa/client/PresentationModalityComponent.h>

using namespace w3c::voiceinteraction::ipa::client;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

class ConsoleTextModalityComponent : public ModalityComponent,
    public CaptureModalityComponent, public PresentationModalityComponent {
public:
    ConsoleTextModalityComponent();

    const std::list<InteractionType> getSupportedInteractionTypes() const override;

    void startCapture(const std::shared_ptr<CaptureModalityComponentListener>& listener) override;

    void stopCapture() override;

    void present(const std::shared_ptr<MultiModalData>& output) override;

    const static ModalityType MODALITY;

private:
    /**
     * Asynchronously started method to capture user input from the console.
     * @param listener the listener to inform, once the user entered data
     */
 void captureInputAsynchronously(
     std::shared_ptr<CaptureModalityComponentListener> mediator);

    const static std::string ID;
    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

} // namespace client
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // CONSOLETEXTMODALITYCOMPONENT_H
