﻿/*
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

/**
 * Constructs a new object.
 * @param multiModalInputs The multimodal inputs to be sent to the client.
 */
ClientRequest::ClientRequest(const std::shared_ptr<SessionId>& sessionIdentifier,
              const std::shared_ptr<RequestId>& requestIdentifier,
              const std::shared_ptr<MultiModalInputs>& multiModalInputs,
              const std::shared_ptr<AudioData>& audioDataToSend,
              const std::shared_ptr<MetaData> metaDataToSend)
    : sessionId(sessionIdentifier), requestId(requestIdentifier),
        inputs(multiModalInputs), audioData(audioDataToSend),
        metaData(metaDataToSend) {
}

/**
 * Destroys the object.
 */
ClientRequest::~ClientRequest() {

}

/**
 * Returns the session id of the session this response belongs to.
 * @return The session id of the session this response belongs to.
 */
const std::shared_ptr<SessionId> ClientRequest::getSessionId() const {
    return sessionId;
}

/**
 * Sets the session identifier.
 * @param sessionIdentifier the new session identifier
 */
void ClientRequest::setSessionId(
    const std::shared_ptr<SessionId>& sessionIdentifier) {
    sessionId = sessionIdentifier;
}

/**
 * Returns the request id of the request this response belongs to.
 * @return The request id of the request this response belongs to.
 */
const std::shared_ptr<RequestId>& ClientRequest::getRequestId() const {
    return requestId;
}

/**
 * Returns the audio data to be played to the user.
 * @return The audio data to be played to the user.
 */
const std::shared_ptr<AudioData>& ClientRequest::getAudioData() {
    return audioData;
}

/**
 * Returns the multimodal inputs to be sent to the client.
 * qreturn The multimodal inputs to be sent to the client.
 */
const std::shared_ptr<MultiModalInputs>& ClientRequest::getMultiModalInputs() {
    return inputs;
}

/**
 * Returns the metadata of the request.
 * @return The metadata of the request.
 */
const std::shared_ptr<MetaData>& ClientRequest::getMetaData() {
    return metaData;
}

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
