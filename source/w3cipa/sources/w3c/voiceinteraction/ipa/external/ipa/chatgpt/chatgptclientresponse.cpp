#include "chatgptclientresponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

ChatGPTClientResponse::ChatGPTClientResponse(const std::shared_ptr<MultiModalOutputs> &outputs)
    : ClientResponse(outputs) {
}

const AudioData& ChatGPTClientResponse::getAudioData() {

}

const MultiModalOutput& ChatGPTClientResponse::getMultiModalOutput() {

}

const RequestId& ChatGPTClientResponse::getRequestId() {

}

const SessionId& ChatGPTClientResponse::getSessionId() {

}

} // chatgpt
} // ipa
} // external
} // ipa
} // voiceinteraction
} // w3c
