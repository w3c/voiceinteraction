///////////////////////////////////////////////////////////
//  ClientResponse.h
//  Implementation of the Interface ClientResponse
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
#define EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_

#include <memory>

#include "AudioData.h"
#include "MultiModalOutputs.h"
#include "RequestId.h"
#include "SessionId.h"
#include "MetaData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request to the client.
 */
class ClientResponse
{

public:
    /**
     * Constructs a new object.
     * @param multiModalOutputs The multimodal outputs to be returned to the client.
     */
    ClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                   const std::shared_ptr<RequestId>& requestIdentifier,
                   const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
                   const std::shared_ptr<AudioData>& audioDataToSend,
                   const std::shared_ptr<MetaData> metaDataToSend)
        : sessionId(sessionIdentifier), requestId(requestIdentifier),
            outputs(multiModalOutputs), audioData(audioDataToSend),
            metaData(metaDataToSend) {
    }

    /**
     * Destroys the object.
     */
    virtual ~ClientResponse() {

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
     * Returns the multimodal outputs to be returned to the client.
     * qreturn The multimodal outputs to be returned to the client.
     */
    virtual const std::shared_ptr<MultiModalOutputs> getMultiModalOutputs() {
        return outputs;
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
    std::shared_ptr<MultiModalOutputs> outputs;
    /** The metadata. */
    std::shared_ptr<MetaData> metaData;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EA_9A15E3C9_7222_460b_AEDE_1EDEEE5E9298__INCLUDED_)
