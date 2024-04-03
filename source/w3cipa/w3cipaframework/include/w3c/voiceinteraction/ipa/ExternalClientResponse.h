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

#if !defined(EXTERNAL_CLIENT_RESPONSE_H)
#define EXTERNAL_CLIENT_RESPONSE_H

#include <memory>

#include "CallResult.h"
#include "ErrorMessage.h"
#include "MultiModalOutputs.h"
#include "RequestId.h"
#include "SessionId.h"
#include "SemanticInterpretation.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request to the client.
 * @author Dirk Schnelle-Walka
 */
class ExternalClientResponse
{
public:
    /**
     * Constructs a new object with a meaningful result
     * @param sessionIdentifier identifier of the session
     * @param requestIdentifier identifier of the request
     * @param multiModalOutputs The multimodal outputs to be returned to the
     *          client.
     * @param semanticInterpretation semantic interpretation of an utterance
     */
    ExternalClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                   const std::shared_ptr<RequestId>& requestIdentifier,
                   const std::shared_ptr<MultiModalOutputs>& multiModalOutputs,
                   const std::shared_ptr<SemanticInterpretation> semanticInterpretation);

    /**
     * Constructs a new object.
     * @param sessionIdentifier identifier of the session
     * @param requestIdentifier identifier of the request
     * @param errorMessage the error to be returned
     */
    ExternalClientResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                           const std::shared_ptr<RequestId>& requestIdentifier,
                           const std::shared_ptr<ErrorMessage>& errorMessage);

    /**
     * Destroys the object.
     */
    virtual ~ExternalClientResponse();

    /**
     * Returns the session id of the session this response belongs to.
     * @return The session id of the session this response belongs to.
     */
    const std::shared_ptr<SessionId> getSessionId() const;

    /**
     * Returns the request id of the request this response belongs to.
     * @return The request id of the request this response belongs to.
     */
    const std::shared_ptr<RequestId>& getRequestId() const;

    /**
     * Returns the multimodal outputs to be returned to the client.
     * @return The multimodal outputs to be returned to the client.
     */
    const std::shared_ptr<MultiModalOutputs> getMultiModalOutputs() const;

    /**
     * Returns the multimodal outputs to be returned to the client.
     * @return The multimodal outputs to be returned to the client.
     */
    const std::shared_ptr<SemanticInterpretation> getSemanticInterpretation() const;

    /**
     * Checks if there was an error in the call.
     * @return {@link CallResult#SUCCESS} in case there was no error.
     */
    CallResult getCallResult() const;

    /**
     * Checks if this reponse includes an error
     * @return {@code true} if the response includes an error
     */
    bool hasError() const;

    /**
     * Retrieves a potentially available error message.
     * @return the error message
     */
    const std::shared_ptr<ErrorMessage> getErrorMessage() const;
private:
    /** The session id. */
    std::shared_ptr<SessionId> sessionId;
    /** The request id. */
    std::shared_ptr<RequestId> requestId;
    /** The multimodal outputs to be returned to the client. */
    std::shared_ptr<MultiModalOutputs> outputs;
    /** Semantic interpretation of an utterance. */
    std::shared_ptr<SemanticInterpretation> interpretation;
    /** Optionalla a caught error. */
    std::shared_ptr<ErrorMessage> error;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EXTERNAL_CLIENT_RESPONSE_H)
