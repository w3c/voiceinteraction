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
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

/**
 * @brief An IPA Provider for ChatGPT.
 * @author Dirk Schnelle-Walka
 */
class ChatGPTIPAProvider : public IPAProvider {
public:
    ChatGPTIPAProvider();
    virtual ~ChatGPTIPAProvider() {
    }

    const std::shared_ptr<ExternalClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request) override;

    const std::string getId() const override {
        return ID;
    }

    const std::list<ModalityType> getSupportedModalityTypes() const override;

    const std::list<Language>& getSupportedLanguages() const override;

   private:
    /** Languages supported by this provider. */
    std::list<Language> supportedLanguages;

    /** Id of this IP provider. */
    const static std::string ID;
    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

} // chatgpt
} // ipa
} // external
} // namespace reference
} // ipa
} // voiceinteraction
} // w3c

#endif // CHATGPTADAPTER_H
