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

#ifndef REFERENCEIPADIALOGMANAGER_H
#define REFERENCEIPADIALOGMANAGER_H

#include <memory>

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/IPADataProcessor.h>
#include <w3c/voiceinteraction/ipa/ExternalIPAResponse.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace dialog {

/**
 * A reference implementation of an IPA Dialog Manager.
 * @author Dirk Schnelle-Walka
 */
class ReferenceIPADialogManager : public IPADataProcessor {
public:
    /**
     * Construc a new instance.
     */
    ReferenceIPADialogManager();

    void processIPAData(std::shared_ptr<IPAData> data) override;

private:
    /**
     * Create a multimodal output from an error message.
     * @param error the error message
     * @return the multimodal output
     */
    std::shared_ptr<MultiModalOutputs> createOutputFromError(
        const std::shared_ptr<ErrorMessage>& error);

    void processIPAData(const std::shared_ptr<ExternalIPAResponse>& request);

    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEIPADIALOGMANAGER_H
