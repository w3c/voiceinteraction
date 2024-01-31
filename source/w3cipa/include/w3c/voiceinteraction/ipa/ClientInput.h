///////////////////////////////////////////////////////////
//  ClientInput.h
//  Implementation of the Interface ClientInput
//  Created on:      13-Jun-2023 21:09:30
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)
#define EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_

#include <memory>

#include "ClientRequest.h"
#include "ClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * The interface for the client input.
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

#endif // !defined(EA_FDD868C2_7466_4191_8546_AA16ADA40292__INCLUDED_)
