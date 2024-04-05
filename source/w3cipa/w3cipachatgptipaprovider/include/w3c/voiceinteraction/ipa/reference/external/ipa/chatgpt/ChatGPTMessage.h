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

#ifndef CHATGPTMESSAGE_H
#define CHATGPTMESSAGE_H

#include <nlohmann/json.hpp>

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace external {
namespace ipa {
namespace chatgpt {

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


} // chatgpt
} // ipa
} // external
} // namespace reference
} // ipa
} // voiceinteraction
} // w3c

#endif // CHATGPTMESSAGE_H
