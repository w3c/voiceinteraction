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

#include <w3c/voiceinteraction/ipa/dialog/ModalityComponent.h>
#include <w3c/voiceinteraction/ipa/dialog/OutputModalityComponent.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace dialog {

class ConsoleTextModalityComponent : public ModalityComponent,
                                     public OutputModalityComponent {
public:
    ConsoleTextModalityComponent();

    const std::list<IOType> getSupportedIOTypes() const;

    void handleOutput(const std::shared_ptr<MultiModalOutput>& output);

    const static ModalityType MODALITY;

private:
    const static std::string ID;
    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

} // namespace dialog
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // CONSOLETEXTMODALITYCOMPONENT_H
