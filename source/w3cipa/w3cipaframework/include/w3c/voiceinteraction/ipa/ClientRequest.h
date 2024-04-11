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

#if !defined(CLIENT_REQUEST_H)
#define CLIENT_REQUEST_H

#include <memory>

#include "AudioData.h"
#include "MultiModalInputs.h"
#include "MetaData.h"
#include "IPAData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request to the client.
 * @author Dirk Schnelle-Walka
 */
class ClientRequest : public IPAData {

public:
    /**
     * Constructs a new object.
     * @param multiModalInputs The multimodal inputs to be sent to the client.
     */
    ClientRequest(const std::shared_ptr<SessionId>& sessionIdentifier,
                  const std::shared_ptr<RequestId>& requestIdentifier,
                  const std::shared_ptr<MultiModalInputs>& multiModalInputs,
                  const std::shared_ptr<AudioData>& audioDataToSend,
                  const std::shared_ptr<MetaData> metaDataToSend);

    /**
     * Destroys the object.
     */
    virtual ~ClientRequest();

    /**
     * Returns the audio data to be played to the user.
     * @return The audio data to be played to the user.
     */
    const std::shared_ptr<AudioData>& getAudioData();

    /**
     * Returns the multimodal inputs to be sent to the client.
     * qreturn The multimodal inputs to be sent to the client.
     */
    const std::shared_ptr<MultiModalInputs>& getMultiModalInputs();

    /**
     * Returns the metadata of the request.
     * @return The metadata of the request.
     */
    const std::shared_ptr<MetaData>& getMetaData();

private:
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
