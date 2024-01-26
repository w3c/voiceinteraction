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

    const std::shared_ptr<ClientResponse> processInput(const std::shared_ptr<SessionId>& sessionId, const std::shared_ptr<RequestId>& requestId, const std::shared_ptr<AudioData>& audioData, const std::shared_ptr<MultiModalInputs>& multiModalInputs, const std::shared_ptr<MetaData>& metaData);

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
