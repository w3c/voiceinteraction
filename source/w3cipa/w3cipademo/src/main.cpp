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

#include <memory>

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <w3c/voiceinteraction/ipa/client/ModalityManager.h>

#include "w3c/voiceinteraction/ipa/reference/IntegerRequestId.h"
#include "w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h"
#include "w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h"
#include "w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h"
#include "w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTAdapter.h"
#include "w3c/voiceinteraction/ipa/reference/external/providerselectionservice/ModalityMatchingProviderSelectionStrategy.h"

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
    std::shared_ptr<client::ModalityManager> modalityManager =
        std::make_shared<client::ModalityManager>();
    std::shared_ptr<::reference::client::ConsoleTextModalityComponent> console =
        std::make_shared<::reference::client::ConsoleTextModalityComponent>();
    modalityManager->addModalityComponent(console);
    std::shared_ptr<::reference::external::providerselectionservice::ModalityMatchingProviderSelectionStrategy> providerSelectionStrategy =
        std::make_shared<::reference::external::providerselectionservice::ModalityMatchingProviderSelectionStrategy>();
    std::shared_ptr<ProviderRegistry> registry =
        std::make_shared<ProviderRegistry>(providerSelectionStrategy);
    std::shared_ptr<IPAProvider> chatGPT =
        std::make_shared<::reference::external::ipa::chatgpt::ChatGPTAdapter>();
    registry->addIPAProvider(chatGPT);
    std::shared_ptr<ProviderSelectionService> providerSelectionService =
        std::make_shared<ProviderSelectionService>(registry);

    ::reference::dialog::ReferenceIPAService ipaService(providerSelectionService);

    // Prepare the request
    std::shared_ptr<w3c::voiceinteraction::ipa::RequestId> requestId =
        std::make_shared<::reference::IntegerRequestId>();
    std::shared_ptr<client::InputModalityComponentListener> listener =
        std::make_shared<::reference::client::TakeFirstInputModalityComponentListener>();
    modalityManager->startInput(listener);

    std::shared_ptr<MultiModalInputs> multiModalInputs = listener->getMultiModalInputs();
    std::shared_ptr<ClientRequest> request =
        std::make_shared<ClientRequest>(nullptr, requestId, multiModalInputs,
            nullptr, nullptr);

    // Actually make the request
    std::shared_ptr<ClientResponse> response = ipaService.processInput(request);
    if (response == nullptr) {
        LOG4CPLUS_ERROR(LOGGER, "no response received");
        return -1;
    }

    // Determine the output and process it
    std::shared_ptr<MultiModalOutputs> outputs =
        response->getMultiModalOutputs();
    modalityManager->handleOutput(outputs);

    return 0;
}
