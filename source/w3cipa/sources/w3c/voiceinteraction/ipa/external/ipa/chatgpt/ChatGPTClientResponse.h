#ifndef CHATGPTCLIENTRESPONSE_H
#define CHATGPTCLIENTRESPONSE_H

#include <w3c/voiceinteraction/ipa/ClientResponse.h>


namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

class ChatGPTClientResponse : public ClientResponse {
public:
    ChatGPTClientResponse(const std::shared_ptr<MultiModalOutputs>& outputs);

    const std::shared_ptr<AudioData> getAudioData();
    const std::shared_ptr<MultiModalOutput> getMultiModalOutput();
    const std::shared_ptr<RequestId> getRequestId();
    const std::shared_ptr<SessionId> getSessionId();
};

} // chatgpt
} // ipa
} // external
} // ipa
} // voiceinteraction
} // w3c

#endif // CHATGPTCLIENTRESPONSE_H
