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

#if !defined(CLIENT_RESPONSE_H)
#define CLIENT_RESPONSE_H

#include <memory>

#include "AudioData.h"
#include "MultiModalOutputs.h"
#include "MetaData.h"
#include "IPAData.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request to the client.
 * @author Dirk Schnelle-Walka
 */
class ClientResponse : public IPAData {

public:
    /**
     * Constructs a new object.
     * @param multiModalOutputs The multimodal outputs to be returned to the client.
     */
    ClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                   const std::shared_ptr<RequestId>& requestIdentifier,
                   const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
                   const std::shared_ptr<AudioData>& audioDataToSend,
                   const std::shared_ptr<MetaData> metaDataToSend);

    /**
     * Destroys the object.
     */
    virtual ~ClientResponse();

    /**
     * Returns the audio data to be played to the user.
     * @return The audio data to be played to the user.
     */
    const std::shared_ptr<AudioData>& getAudioData();

    /**
     * Returns the multimodal outputs to be returned to the client.
     * qreturn The multimodal outputs to be returned to the client.
     */
    virtual const std::shared_ptr<MultiModalOutputs> getMultiModalOutputs();

    /**
     * Returns the metadata of the request.
     * @return The metadata of the request.
     */
    const std::shared_ptr<MetaData>& getMetaData();

private:
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

#endif // !defined(CLIENT_RESPONSE_H)
