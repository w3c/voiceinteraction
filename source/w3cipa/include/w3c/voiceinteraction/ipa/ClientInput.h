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

#if !defined(CLIENTINPUT_H)
#define CLIENTINPUT_H

#include <memory>

#include "ClientRequest.h"
#include "ClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The interface for the client input.
 * @author Dirk Schnelle-Walka
 */
class ClientInput
{

public:
    /**
     * Constructs a new object.
     */
    ClientInput() {
    }

    /**
     * Destroys the object.
     */
    virtual ~ClientInput() {
    };

    /**
     * Processes the input from the client.
     * @param sessionId The session id.
     * @param requestId The request id.
     * @param audioData The audio data.
     * @param multiModalInputs The multi modal inputs.
     * @param metaData The meta data.
     */
    virtual const std::shared_ptr<ClientResponse> processInput(const std::shared_ptr<ClientRequest>& request) =0;

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(CLIENTINPUT_H)
