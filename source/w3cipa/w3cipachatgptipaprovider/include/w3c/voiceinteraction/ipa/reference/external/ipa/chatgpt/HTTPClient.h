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

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <list>

#include <nlohmann/json.hpp>
#include <log4cplus/logger.h>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

/**
 * A simple HTTP client for sending POST requests.
 * @author Dirk Schnelle-Walka
 */
class HTTPClient {
public:
    /** 
     * Posts a JSON object to an endpoint.
     * @param endpoint the URL to post to
     * @param data the JSON object to post
     * @param headers the headers to send
     * @return the response as JSON
     * @throws HTTPException if the request fails
     */
    static nlohmann::json post(const std::string& endpoint,
                            const nlohmann::json& data,
                            const std::list<std::string>& headers);

private:
    /** Logger instance. */
    const static log4cplus::Logger LOGGER;
};

}  // namespace ipa
}  // namespace external
}  // namespace reference
}  // namespace ipa
}  // namespace voiceinteraction
}  // namespace w3c
}  // namespace chatgpt

#endif  // HTTPCLIENT_H
