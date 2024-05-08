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

#include "w3c/voiceinteraction/ipa/ClientRequest.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

ClientRequest::ClientRequest(const std::shared_ptr<SessionId>& sessionIdentifier,
              const std::shared_ptr<RequestId>& requestIdentifier,
              const std::shared_ptr<MultiModalInputs>& multiModalInputs,
              const std::shared_ptr<AudioData>& audioDataToSend,
              const std::shared_ptr<MetaData> metaDataToSend)
    : IPAData(sessionIdentifier, requestIdentifier),
        inputs(multiModalInputs), audioData(audioDataToSend),
        metaData(metaDataToSend) {
}

ClientRequest::~ClientRequest() {

}

const std::shared_ptr<AudioData>& ClientRequest::getAudioData() {
    return audioData;
}

const std::shared_ptr<MultiModalInputs>& ClientRequest::getMultiModalInputs() {
    return inputs;
}

const std::shared_ptr<MetaData>& ClientRequest::getMetaData() {
    return metaData;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
