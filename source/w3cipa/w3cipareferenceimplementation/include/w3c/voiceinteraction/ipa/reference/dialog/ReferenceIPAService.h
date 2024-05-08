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

#ifndef REFERENCEIPASERVICE_H
#define REFERENCEIPASERVICE_H

#include <memory>

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/IPADataProcessor.h>
#include <w3c/voiceinteraction/ipa/ClientRequest.h>
#include <w3c/voiceinteraction/ipa/ExternalClientResponse.h>
#include <w3c/voiceinteraction/ipa/external/ipa/IPAService.h>

using namespace w3c::voiceinteraction::ipa::external;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace dialog {

/**
 * @brief A reference implementation of an IPA Service
 * @author Dirk Schnelle-Walka
 */
class ReferenceIPAService : public external::ipa::IPAService, public IPADataProcessor {
public:
    ReferenceIPAService();

    void processIPAData(std::shared_ptr<IPAData> data) override;

private:
    void processIPAData(const std::shared_ptr<ClientRequest>& request);

    void processIPAData(const std::shared_ptr<ExternalClientResponse>& request);


    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
    std::mutex mtx;
    std::condition_variable cv;
};

} // namespace dialog
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // REFERENCEIPASERVICE_H
