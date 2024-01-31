///////////////////////////////////////////////////////////
//  ClientResponse.h
//  Implementation of the Interface ClientResponse
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(CLIENT_REQUEST_H)
#define CLIENT_REQUEST_H

#include <memory>

#include "AudioData.h"
#include "MultiModalInputs.h"
#include "RequestId.h"
#include "SessionId.h"
#include "MetaData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request to the client.
 */
class ClientRequest
{

public:
    /**
     * Constructs a new object.
     * @param multiModalInputs The multimodal inputs to be sent to the client.
     */
    ClientRequest(const std::shared_ptr<SessionId>& sessionIdentifier,
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
    virtual ~ClientRequest() {

    }

    /**
     * Returns the session id of the session this response belongs to.
     * @return The session id of the session this response belongs to.
     */
    const std::shared_ptr<SessionId> getSessionId() const {
        return sessionId;
    }

    /**
     * Returns the request id of the request this response belongs to.
     * @return The request id of the request this response belongs to.
     */
    const std::shared_ptr<RequestId>& getRequestId() const {
        return requestId;
    }

    /**
     * Returns the audio data to be played to the user.
     * @return The audio data to be played to the user.
     */
    const std::shared_ptr<AudioData>& getAudioData() {
        return audioData;
    }

    /**
     * Returns the multimodal inputs to be sent to the client.
     * qreturn The multimodal inputs to be sent to the client.
     */
    const std::shared_ptr<MultiModalInputs>& getMultiModalInputs() {
        return inputs;
    }

    /**
     * Returns the metadata of the request.
     * @return The metadata of the request.
     */
    const std::shared_ptr<MetaData>& getMetaData() {
        return metaData;
    }

    private:
        /** The session id. */
        std::shared_ptr<SessionId> sessionId;
        /** The request id. */
        std::shared_ptr<RequestId> requestId;
        /** The audio data. */
        std::shared_ptr<AudioData> audioData;
        /** The multimodal outputs to be returned to the client. */
        std::shared_ptr<MultiModalInputs> inputs;
        /** The metadata. */
        std::shared_ptr<MetaData> metaData;
    };

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(CLIENT_REQUEST_H)
