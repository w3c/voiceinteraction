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

#include <fstream>
#include <filesystem>

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <log4cplus/loggingmacros.h>


#include <w3c/voiceinteraction/ipa/TextModalityType.h>

#include "w3c/voiceinteraction/ipa/reference/TextMultiModalData.h"

#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTConfiguration.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTMessage.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

const std::string ChatGPTIPAProvider::ID = std::string("ChatGPT");
const log4cplus::Logger ChatGPTIPAProvider::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.ipa.external.ChatGPT"));

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata)
{
    size_t num_bytes = size * nmemb;
    std::string* response = static_cast<std::string*>(userdata);
    response->append(ptr, num_bytes);
    return num_bytes;
}

ChatGPTIPAProvider::ChatGPTIPAProvider() {
    supportedLanguages = { 
      Language::DE, 
      Language::EN, 
      Language::ES, 
      Language::FR, 
      Language::IT, 
      Language::JA,
      Language::NL,
      Language::PL,
      Language::PT,
      Language::RU,
      Language::ZH };
}

void ChatGPTIPAProvider::initialize() {
    std::filesystem::path configFile("config/ChatGPTIPAProvider.json");
    // Check if the configuration file exists
    std::error_code ec;
    if (!std::filesystem::exists(configFile, ec)) {
      LOG4CPLUS_ERROR_FMT(
          LOGGER,
          LOG4CPLUS_TEXT(
              "ChatGPT IPA provider configuration file %s not found. %s (%d)"),
          configFile.c_str(), ec.message().c_str(), ec.value());
      return;
    }
    // Parse the configuration file and initialize this provider
    std::ifstream file(configFile);
    nlohmann::json json = nlohmann::json::parse(file);
    ChatGPTConfiguration configuration = json;
    endpoint = configuration.endpoint;
    model = configuration.model;
    key = configuration.key;
    systemMessage = configuration.systemMessage;
    LOG4CPLUS_INFO_FMT(LOGGER,
                     LOG4CPLUS_TEXT("ChatGPT IPA provider initialized"));
}

const std::list<ModalityType> ChatGPTIPAProvider::getSupportedModalityTypes() const {
    std::list<ModalityType> types = { TextModalityType() };
    return types;
}

const std::list<Language>& ChatGPTIPAProvider::getSupportedLanguages() const {
    return supportedLanguages;
}

const std::shared_ptr<ExternalIPAResponse> ChatGPTIPAProvider::processInput(
    const std::shared_ptr<IPARequest> &request) {
    const std::string& sessionId = request->getSessionId()->toString();
    const std::string& requestId = request->getRequestId()->toString();

    CURL* curl = curl_easy_init();
    if(curl == nullptr) {
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("%s %s failed to initialize CURL"),
                           sessionId.c_str(), requestId.c_str());

        return nullptr;
    }
    // Set the header and API key
    struct curl_slist *headers = NULL;
    std::string authorization = "Authorization: Bearer ";
    authorization += key;
    headers = curl_slist_append(headers, authorization.c_str());
                                headers = curl_slist_append(
                                    headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

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
    ChatGPTJSONRequest req;
    req.model = model;
    ChatGPTMessage actualSystemMessage{"system", systemMessage.c_str()};
    std::shared_ptr<MultiModalDataCollection> multiModalInputs =
        request->getMultiModalInputs();
    std::shared_ptr<MultiModalData> input =
        multiModalInputs->getMultiModalData(TextMultiModalInput::MODALITY);
    std::shared_ptr<TextMultiModalInput> textInput =
        std::dynamic_pointer_cast<TextMultiModalInput>(input);
    const std::string& text = textInput->getText();
    ChatGPTMessage userMessage { "user", text };
    req.messages = std::vector({actualSystemMessage, userMessage});
    req.temperature = 1;
    req.top_p = 1;
    req.max_tokens = 256;
    req.presence_penalty = 0;
    req.frequency_penalty = 0;
    nlohmann::json data = req;
    std::string dataString = data.dump(2, ' ');
    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("%s %s sending request in %s to ChatGPT: %s"),
                       sessionId.c_str(), requestId.c_str(),
                       textInput->getLanguage().toString().c_str(),
                       dataString.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataString.c_str());

    CURLcode res = curl_easy_perform(curl);
    headers = nullptr;
    if (res != CURLE_OK) {
        std::string curlError(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("%s %s failed to get HTTP response code: %s"),
                           sessionId.c_str(), requestId.c_str(),
                           curlError.c_str());
        std::shared_ptr<ErrorMessage> error =
            std::make_shared<ErrorMessage>(res, curlError, ID);
        std::shared_ptr<ExternalIPAResponse> out =
            std::make_shared<ExternalIPAResponse>(request->getSessionId(),
                request->getRequestId(), error);
        return out;
    }

    long http_code = 0;
    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (res != CURLE_OK){
        std::string curlError(curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("%s %s failed to get HTTP response code: %s"),
                           sessionId.c_str(), requestId.c_str(),
                           curlError.c_str());
        std::shared_ptr<ErrorMessage> error =
            std::make_shared<ErrorMessage>(res, curlError, ID);
        std::shared_ptr<ExternalIPAResponse> out =
            std::make_shared<ExternalIPAResponse>(request->getSessionId(),
                                                     request->getRequestId(), error);
        return out;
    }

    curl_easy_cleanup(curl);
    if (http_code != 200) {
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("%s %s failed with HTTP error code: %ld"),
                           sessionId.c_str(), requestId.c_str(), http_code);
        LOG4CPLUS_WARN_FMT(LOGGER, LOG4CPLUS_TEXT("%s %s response: %s"),
                           sessionId.c_str(), requestId.c_str(),
                           response.c_str());
        std::stringstream errorMessage;
        errorMessage << "ChatGPT failed with HTTP error code " << http_code;
        std::shared_ptr<ErrorMessage> error =
            std::make_shared<ErrorMessage>(res, errorMessage.str(), ID);

        std::shared_ptr<ExternalIPAResponse> out =
            std::make_shared<ExternalIPAResponse>(request->getSessionId(),
                                                     request->getRequestId(), error);

        return out;
    }

    // Trim whitespaces
    response.erase(response.find_last_not_of(" \n\r\t") + 1);
    response.erase(0, response.find_first_not_of(" \n\r\t"));

    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("%s %s received response from ChatGPT: %s"),
                       sessionId.c_str(), requestId.c_str(), response.c_str());

    // Parse the response as JSON
    nlohmann::json responseData = nlohmann::json::parse(response);
    ChatGPTJSONResponse parsedResponse = responseData;
    std::string textOutput = parsedResponse.choices[0].message.content;
    std::shared_ptr<MultiModalData> output =
        std::make_shared<TextMultiModalInput>(textOutput);
    std::shared_ptr<MultiModalDataCollection> outputs =
        std::make_shared<MultiModalDataCollection>();
    outputs->addMultiModalData(output);
    std::shared_ptr<ExternalIPAResponse> out =
        std::make_shared<ExternalIPAResponse>(request->getSessionId(),
            request->getRequestId(), outputs, nullptr);

    return out;
}


} // namespace chatgpt
} // namespace ipa
} // namespace external
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
