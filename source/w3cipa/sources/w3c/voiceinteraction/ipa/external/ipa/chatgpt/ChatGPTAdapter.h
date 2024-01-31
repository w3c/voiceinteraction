#ifndef CHATGPTADAPTER_H
#define CHATGPTADAPTER_H

#include <log4cplus/logger.h>

#include <w3c/voiceinteraction/ipa/IPAProvider.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

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
