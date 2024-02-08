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

#ifndef CHATGPTADAPTER_H
#define CHATGPTADAPTER_H

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/external/ipa/IPAProvider.h>

using namespace w3c::voiceinteraction::ipa::external::ipa;

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

/**
 * @brief An IPA Provider for ChatGPT.
 * @author Dirk Schnelle-Walka
 */
class ChatGPTAdapter : public IPAProvider {
public:
    ChatGPTAdapter();
    virtual ~ChatGPTAdapter() {
    }

    const std::shared_ptr<ClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request);

    const std::string getId() const {
        return ID;
    }

private:
    const static std::string ID;
    const static log4cplus::Logger LOGGER;
};

} // chatgpt
} // ipa
} // external
} // ipa
} // voiceinteraction
} // w3c

#endif // CHATGPTADAPTER_H
