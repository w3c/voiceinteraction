#include "ChatGPTClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

ChatGPTClientResponse::ChatGPTClientResponse(
    const std::shared_ptr<MultiModalOutputs> &outputs)
    : ClientResponse(outputs) {
}

const std::shared_ptr<AudioData> ChatGPTClientResponse::getAudioData() {
    return nullptr;
}

const std::shared_ptr<MultiModalOutput> ChatGPTClientResponse::getMultiModalOutput() {
    return nullptr;
}

const std::shared_ptr<RequestId> ChatGPTClientResponse::getRequestId() {
    return nullptr;
}

const std::shared_ptr<SessionId> ChatGPTClientResponse::getSessionId() {
    return nullptr;
}

} // chatgpt
} // ipa
} // external
} // ipa
} // voiceinteraction
} // w3c
