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

#if !defined(EXTERNAL_IPA_RESPONSE_H)
#define EXTERNAL_IPA_RESPONSE_H

#include <memory>

#include "CallResult.h"
#include "ErrorMessage.h"
#include "MultiModalDataCollection.h"
#include "IPAData.h"
#include "SemanticInterpretation.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * This interface is used to return the results of a request of an IPA.
 * @author Dirk Schnelle-Walka
 */
class ExternalIPAResponse : public IPAData {
public:
    /**
     * Constructs a new object with a meaningful result
     * @param sessionIdentifier identifier of the session
     * @param requestIdentifier identifier of the request
     * @param multiModalOutputs The multimodal outputs to be returned to the
     *          client.
     * @param semanticInterpretation semantic interpretation of an utterance
     */
    ExternalIPAResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                   const std::shared_ptr<RequestId>& requestIdentifier,
                   const std::shared_ptr<MultiModalDataCollection>& multiModalOutputs,
                   const std::shared_ptr<SemanticInterpretation> semanticInterpretation);

    /**
     * Constructs a new object.
     * @param sessionIdentifier identifier of the session
     * @param requestIdentifier identifier of the request
     * @param errorMessage the error to be returned
     */
    ExternalIPAResponse(const std::shared_ptr<SessionId>& sessionIdentifier,
                           const std::shared_ptr<RequestId>& requestIdentifier,
                           const std::shared_ptr<ErrorMessage>& errorMessage);

    /**
     * Destroys the object.
     */
    virtual ~ExternalIPAResponse();

    /**
     * Returns the multimodal outputs to be returned to the client.
     * @return The multimodal outputs to be returned to the client.
     */
    const std::shared_ptr<MultiModalDataCollection> getMultiModalOutputs() const;

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
    /** The multimodal outputs to be returned to the client. */
    std::shared_ptr<MultiModalDataCollection> outputs;
    /** Semantic interpretation of an utterance. */
    std::shared_ptr<SemanticInterpretation> interpretation;
    /** Optionalla a caught error. */
    std::shared_ptr<ErrorMessage> error;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EXTERNAL_IPA_RESPONSE_H)
