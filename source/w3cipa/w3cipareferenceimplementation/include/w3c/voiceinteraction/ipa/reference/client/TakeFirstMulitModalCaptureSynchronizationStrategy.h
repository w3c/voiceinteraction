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

#ifndef TAKEFIRSTINPUTMODALITYCOMPONENTLISTENER_H
#define TAKEFIRSTINPUTMODALITYCOMPONENTLISTENER_H

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/client/MulitModalCaptureSynchronizationStrategy.h>

using namespace w3c::voiceinteraction::ipa;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

/**
 * A listener for inputs from input modality components that takes the
 * first received input as the input to the IPA.
 * @author Dirk Schnelle-Walka
 */
class TakeFirstMulitModalCaptureSynchronizationStrategy
    : public ::client::MulitModalCaptureSynchronizationStrategy {

public:
    /**
     * Constructs a new object.
     */
 TakeFirstMulitModalCaptureSynchronizationStrategy(
     const std::shared_ptr<::client::InteractionManager>& im);

    void onMultiModalInput(std::shared_ptr<MultiModalData> input) override;

private:
    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

} // namespace client
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // TAKEFIRSTINPUTMODALITYCOMPONENTLISTENER_H
