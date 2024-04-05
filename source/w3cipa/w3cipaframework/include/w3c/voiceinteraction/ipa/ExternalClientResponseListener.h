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

#if !defined(EXTERNAL_CLIENT_RESPONSE_LISTENER_H)
#define EXTERNAL_CLIENT_RESPONSE_LISTENER_H

#include <memory>

#include "ExternalClientResponse.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {

/**
 * Listener for {@link ExternalClientResponse}s.
 * @author Dirk Schnelle-Walka
 */
class ExternalClientResponseListener {
public:
    /**
     * Process the external client response.
     * @param response the response
     */
    virtual void  processExternalClientResponse(
        const std::shared_ptr<ExternalClientResponse>& response) = 0;
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(EXTERNAL_CLIENT_RESPONSE_LISTENER_H)
