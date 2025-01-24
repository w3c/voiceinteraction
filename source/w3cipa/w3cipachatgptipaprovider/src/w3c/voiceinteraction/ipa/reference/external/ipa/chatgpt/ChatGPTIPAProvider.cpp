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

#include <filesystem>
#include <fstream>

#include <log4cplus/loggingmacros.h>
#include <nlohmann/json.hpp>

#include <w3c/voiceinteraction/ipa/TextModalityType.h>

#include "w3c/voiceinteraction/ipa/reference/TextMultiModalData.h"

#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTConfiguration.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTMessage.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPException.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPClient.h"

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
  // Load the configuration from the file
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

    std::list<std::string> headers;
    std::string authorization = "Authorization: Bearer ";
    authorization += key;
    headers.push_back(authorization);
    headers.push_back("Content-Type: application/json");

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
    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("%s %s sending request in %s to ChatGPT"),
                       sessionId.c_str(), requestId.c_str(),
                       textInput->getLanguage().toString().c_str());
    nlohmann::json response;
    try {
      response = HTTPClient::post(endpoint, data, headers);
    } catch (HTTPException e) {
        LOG4CPLUS_WARN_FMT(
            LOGGER, LOG4CPLUS_TEXT("%s %s failed to get HTTP response code: %s"),
            sessionId.c_str(), requestId.c_str(), e.what());
        std::shared_ptr<ErrorMessage> error =
            std::make_shared<ErrorMessage>(e.getCode(), e.what(), ID);
        std::shared_ptr<ExternalIPAResponse> out =
            std::make_shared<ExternalIPAResponse>(request->getSessionId(),
                                                request->getRequestId(), error);
        return out;
    }

    // Parse the response as JSON
    ChatGPTJSONResponse parsedResponse = response;
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
