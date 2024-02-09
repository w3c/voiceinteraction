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

#include <string>
#include <memory>

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <w3c/voiceinteraction/ipa/dialog/ModalityManager.h>

#include "w3c/voiceinteraction/ipa/TextMultiModalInput.h"
#include "w3c/voiceinteraction/ipa/dialog/ConsoleTextModalityComponent.h"
#include "w3c/voiceinteraction/ipa/dialog/ReferenceIPAService.h"
#include "w3c/voiceinteraction/ipa/external/providerselectionservice/ReferenceProviderSelectionService.h"

using namespace w3c::voiceinteraction::ipa;

static log4cplus::Logger LOGGER;


int main() {
    LOGGER = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));

    // Initialization and deinitialization.
    log4cplus::Initializer initializer;
    log4cplus::PropertyConfigurator::doConfigure(
        LOG4CPLUS_TEXT("config/log4cplus.properties"));
    LOG4CPLUS_INFO(LOGGER, LOG4CPLUS_TEXT("W3C IPA started"));

    // Build up the components
    std::shared_ptr<dialog::ModalityManager> modalityManager =
        std::make_shared<dialog::ModalityManager>();
    std::shared_ptr<dialog::ConsoleTextModalityComponent> console =
        std::make_shared<dialog::ConsoleTextModalityComponent>();
    modalityManager->addModalityComponent(console);
    std::shared_ptr<external::providerselectionservice::ReferenceProviderSelectionService> providerSelectionService =
        std::make_shared<external::providerselectionservice::ReferenceProviderSelectionService>();
    dialog::ReferenceIPAService ipaService(providerSelectionService);

    // Prepare the request
    //w3c::voiceinteraction::ipa::SessionId sessionId;
    //w3c::voiceinteraction::ipa::RequestId requestId;
    //w3c::voiceinteraction::ipa::AudioData audioData;
    std::shared_ptr<MultiModalInputs> multiModalInputs =
        std::make_shared<MultiModalInputs>();
    std::string input("Say something motivational");
    std::shared_ptr<TextMultiModalInput> multiModalInput =
        std::make_shared<TextMultiModalInput>(input);
    multiModalInputs->addMultiModalInput(multiModalInput);
    //w3c::voiceinteraction::ipa::MetaData metaData;
    std::shared_ptr<ClientRequest> request =
        std::make_shared<ClientRequest>(nullptr, nullptr, multiModalInputs,
            nullptr, nullptr);

    // Actually make the request
    LOG4CPLUS_INFO_FMT(LOGGER, LOG4CPLUS_TEXT("Sending input to ChatGPT: %s"),
                       input.c_str());
    std::shared_ptr<ClientResponse> response = ipaService.processInput(request);
    if (response == nullptr) {
        LOG4CPLUS_ERROR(LOGGER, "no response received");
        return -1;
    }

    // Determine the output
    std::shared_ptr<MultiModalOutputs> outputs =
        response->getMultiModalOutputs();
    std::shared_ptr<MultiModalOutput> output =
        outputs->getMultiModalOutput(TextMultiModalInput::MODALITY);
    console->handleOutput(output);

    return 0;
}
