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
#include <nlohmann/json.hpp>
#include <log4cplus/loggingmacros.h>

#include "../../../TextMultiModalInput.h"
#include "../../../TextMultiModalOutput.h"

#include "ChatGPTAdapter.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace external {
namespace ipa {
namespace chatgpt {

const std::string ChatGPTAdapter::ID = std::string("ChatGPT");
const log4cplus::Logger ChatGPTAdapter::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.ipa.external.chatgpt"));

ChatGPTAdapter::ChatGPTAdapter() {
}

size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata)
{
    size_t num_bytes = size * nmemb;
    std::string* response = static_cast<std::string*>(userdata);
    response->append(ptr, num_bytes);
    return num_bytes;
}

struct ChatGPTMessage {
    std::string role;
    std::string content;
};

void to_json(nlohmann::json& j, const ChatGPTMessage& message) {
    j = nlohmann::json {
        {"role", message.role},
        {"content", message.content}
    };
}

void from_json(const nlohmann::json& j, ChatGPTMessage& message) {
    j.at("role").get_to(message.role);
    j.at("content").get_to(message.content);
}

struct ChatGPTJSONRequest {
    std::string model;
    std::vector<ChatGPTMessage> messages;
    int temperature;
    int max_tokens;
    int top_p;
    int frequency_penalty;
    int presence_penalty;

};

void to_json(nlohmann::json& j, const ChatGPTJSONRequest& request) {
    j = nlohmann::json {
        {"model", request.model},
        {"messages", request.messages},
        {"temperature", request.temperature},
        {"max_tokens", request.max_tokens},
        {"top_p", request.top_p},
        {"frequency_penalty", request.frequency_penalty},
        {"presence_penalty", request.presence_penalty}
    };
}

void from_json(const nlohmann::json& j, ChatGPTJSONRequest& request) {
    j.at("model").get_to(request.model);
    j.at("temperature").get_to(request.temperature);
    j.at("max_tokens").get_to(request.max_tokens);
    j.at("top_p").get_to(request.top_p);
    j.at("frequency_penalty").get_to(request.frequency_penalty);
    j.at("presence_penalty").get_to(request.presence_penalty);
}

struct ChatGPTChoice {
    int index;
    ChatGPTMessage message;
    std::string finishReason;
};

void from_json(const nlohmann::json& j, ChatGPTChoice& choices) {
    j.at("index").get_to(choices.index);
    j.at("message").get_to(choices.message);
    j.at("finish_reason").get_to(choices.finishReason);
}

struct ChatGPTJSONResponse {
    std::string id;
    std::string object;
    std::string model;
    std::vector<ChatGPTChoice> choices;
};

void from_json(const nlohmann::json& j, ChatGPTJSONResponse& response) {
    j.at("id").get_to(response.id);
    j.at("object").get_to(response.object);
    j.at("choices").get_to(response.choices);
}

const std::shared_ptr<ClientResponse> ChatGPTAdapter::processInput(
    const std::shared_ptr<ClientRequest> &request) {
    CURL* curl = curl_easy_init();
    if(curl == nullptr) {
        LOG4CPLUS_WARN(LOGGER, LOG4CPLUS_TEXT("Failed to initialize CURL"));

        return nullptr;
    }
    // Set the header and API key
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers,
                                "Authorization: Bearer OPENAI-DEVELOPER-KEY");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // TODO Remove this disabling of SSL verification
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);


    // Set the URL to the OpenAI API endpoint
    std::string apiUrl = "https://api.openai.com/v1/chat/completions";
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

    // Set the callback function for libcurl
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Set the payload
    ChatGPTJSONRequest req;
    req.model = std::string("gpt-3.5-turbo");
    ChatGPTMessage systemMessage {"system",
                                "You are a junkie who is tired of this world."};
    std::shared_ptr<MultiModalInputs> multiModalInputs =
        request->getMultiModalInputs();
    std::shared_ptr<MultiModalInput> input =
        multiModalInputs->getMultiModalInput(TextMultiModalInput::MODALITY);
    std::shared_ptr<TextMultiModalInput> textInput =
        std::dynamic_pointer_cast<TextMultiModalInput>(input);
    const std::string& text = textInput->getTextInput();
    ChatGPTMessage userMessage { "user", text };
    req.messages = std::vector({ systemMessage, userMessage });
    req.temperature = 1;
    req.top_p = 1;
    req.max_tokens = 256;
    req.presence_penalty = 0;
    req.frequency_penalty = 0;
    nlohmann::json data = req;
    std::string dataString = data.dump();
    LOG4CPLUS_INFO_FMT(LOGGER, LOG4CPLUS_TEXT("Sending request to ChatGPT: %s"),
                       dataString.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataString.c_str());

    CURLcode res = curl_easy_perform(curl);
    headers = nullptr;
    if (res != CURLE_OK) {
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("Failed to get HTTP response code: %s"),
                           curl_easy_strerror(res));
        curl_easy_cleanup(curl);

        return nullptr;
    }

    long http_code = 0;
    res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (res != CURLE_OK){
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("Failed to get HTTP response code: %s"),
                           curl_easy_strerror(res));
        return nullptr;
        curl_easy_cleanup(curl);
    }

    if (http_code != 200) {
        LOG4CPLUS_WARN_FMT(LOGGER,
                           LOG4CPLUS_TEXT("Failed with HTTP error code: %ld"),
                           http_code);
        LOG4CPLUS_WARN_FMT(LOGGER, LOG4CPLUS_TEXT("response: %s"),
                           response.c_str());
        curl_easy_cleanup(curl);

        return nullptr;
    }
    curl_easy_cleanup(curl);

    // Trim whitespaces
    response.erase(response.find_last_not_of(" \n\r\t") + 1);
    response.erase(0, response.find_first_not_of(" \n\r\t"));

    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("Received response from ChatGPT: %s"),
                       response.c_str());

    // Parse the response as JSON
    nlohmann::json responseData = nlohmann::json::parse(response);
    ChatGPTJSONResponse parsedResponse = responseData;
    std::string textOutput = parsedResponse.choices[0].message.content;
    std::shared_ptr<MultiModalOutput> output =
        std::make_shared<TextMultiModalOutput>(textOutput);
    std::shared_ptr<MultiModalOutputs> outputs =
        std::make_shared<MultiModalOutputs>();
    outputs->addMultiModalOutput(output);
    std::shared_ptr<ClientResponse> out =
        std::make_shared<ClientResponse>(request->getSessionId(),
            request->getRequestId(), outputs, nullptr, nullptr);

    return out;
}


} // namespace chatgpt
} // namespace ipa
} // namespace external
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
