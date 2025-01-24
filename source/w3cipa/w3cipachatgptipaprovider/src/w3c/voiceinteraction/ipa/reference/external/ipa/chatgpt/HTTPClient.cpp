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

#include <curl/curl.h>
#include <log4cplus/loggingmacros.h>

#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPException.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPClient.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

const log4cplus::Logger HTTPClient::LOGGER =
    log4cplus::Logger::getInstance(
        LOG4CPLUS_TEXT("w3c.voiceinteraction.ipa.external.HTTPClient"));

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    size_t num_bytes = size * nmemb;
    std::string* response = static_cast<std::string*>(userdata);
    response->append(ptr, num_bytes);
    return num_bytes;
}

nlohmann::json HTTPClient::post(const std::string& endpoint,
                                const nlohmann::json& data,
                                const std::list<std::string>& headers) {
    CURL* curl = curl_easy_init();
    if (curl == nullptr) {
        return nullptr;
    }
    // Set the header and API key
    struct curl_slist* curlHeaders = NULL;
    for (std::string header : headers) {
        curlHeaders = curl_slist_append(curlHeaders, header.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curlHeaders);

    // Set the SSL options
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L);
    curl_easy_setopt(curl, CURLOPT_CAINFO, "config/cacert.pem");

    // Set the URL to the OpenAI API endpoint
    curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());

    // Set the callback function for libcurl
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Set the payload
    std::string dataString = data.dump(2, ' ');
    LOG4CPLUS_INFO_FMT(LOGGER, LOG4CPLUS_TEXT("sending request %s to %s"),
                        dataString.c_str(), endpoint.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataString.c_str());

    CURLcode res = curl_easy_perform(curl);
    curlHeaders = nullptr;
    if (res != CURLE_OK) {
        std::string curlError(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        LOG4CPLUS_WARN_FMT(
        LOGGER, LOG4CPLUS_TEXT("failed to get HTTP response: %s"),
            curlError.c_str());
        throw HTTPException(res, curlError);
    }

    long httpCode = 0;
    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    if (res != CURLE_OK) {
        std::string curlError(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        LOG4CPLUS_WARN_FMT(
        LOGGER, LOG4CPLUS_TEXT("failed to get HTTP response: %s"),
        curlError.c_str());
        throw HTTPException(res, curlError);
    }

    curl_easy_cleanup(curl);
    if (httpCode != 200) {
        LOG4CPLUS_WARN_FMT(LOGGER,
                LOG4CPLUS_TEXT("failed with HTTP error code: %ld"),
                httpCode);
        LOG4CPLUS_WARN_FMT(LOGGER, LOG4CPLUS_TEXT("response: %s"),
                response.c_str());
        throw HTTPException(res, response);
    }

    // Trim whitespaces
    response.erase(response.find_last_not_of(" \n\r\t") + 1);
    response.erase(0, response.find_first_not_of(" \n\r\t"));

    LOG4CPLUS_INFO_FMT(LOGGER,
                        LOG4CPLUS_TEXT("received response from %s: %s"),
                       endpoint.c_str(), response.c_str());
    
    // Parse the response as JSON
    return nlohmann::json::parse(response);
}


}  // namespace chatgpt
}  // namespace ipa
}  // namespace external
}  // namespace reference
}  // namespace ipa
}  // namespace voiceinteraction
}  // namespace w3c
