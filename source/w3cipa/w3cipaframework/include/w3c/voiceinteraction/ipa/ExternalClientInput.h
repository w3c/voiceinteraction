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

#if !defined(EXTERNAL_CLIENTINPUT_H)
#define EXTERNAL_CLIENTINPUT_H

#include <memory>

#include "ClientRequest.h"
#include "ExternalClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The interface for the external client input.
 * @author Dirk Schnelle-Walka
 */
class ExternalClientInput
{

public:
    /**
     * Constructs a new object.
     */
    ExternalClientInput() {
    }

    /**
     * Destroys the object.
     */
    virtual ~ExternalClientInput() {
    };

    /**
     * Processes the input from the client.
     * @param request the request coming from the client
     */
    virtual const std::shared_ptr<ExternalClientResponse> processInput(
        const std::shared_ptr<ClientRequest>& request) =0;

};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EXTERNAL_CLIENTINPUT_H)
