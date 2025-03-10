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

#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#include <w3c/voiceinteraction/ipa/client/InteractionManager.h>
#include <w3c/voiceinteraction/ipa/external/ipa/LanguageMatchingProviderSelectionStrategy.h>
#include <w3c/voiceinteraction/ipa/external/ipa/ModalityMatchingProviderSelectionStrategy.h>
#include <w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.h>
#include <w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategyList.h>
#include <w3c/voiceinteraction/ipa/external/ProviderSelectionService.h>
#include <w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h>
#include <w3c/voiceinteraction/ipa/reference/client/TakeFirstMulitModalCaptureSynchronizationStrategy.h>
#include <w3c/voiceinteraction/ipa/reference/dialog/ReferenceDialogManager.h>
#include <w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h>
#include <w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.h>

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

    // Cient Layer
    std::shared_ptr<client::InteractionManager> interactionManager =
        std::make_shared<client::InteractionManager>();
    std::shared_ptr<::reference::client::TakeFirstMulitModalCaptureSynchronizationStrategy> synchronizationStrategy =
        std::make_shared<::reference::client::TakeFirstMulitModalCaptureSynchronizationStrategy>(interactionManager);
    interactionManager->setMultimodalCaptureSynchronizationStrategy(
        synchronizationStrategy);
    std::shared_ptr<::reference::client::ConsoleTextModalityComponent> console =
        std::make_shared<::reference::client::ConsoleTextModalityComponent>();

    // Dialog Layer
    std::shared_ptr<::reference::dialog::ReferenceIPAService> ipaService =
        std::make_shared<::reference::dialog::ReferenceIPAService>();
    std::shared_ptr<::reference::dialog::ReferenceIPADialogManager> ipaDialogManager =
        std::make_shared<::reference::dialog::ReferenceIPADialogManager>();

    // External IPA / Services Layer

    // Create a chained filter for selecting the best provider
    std::shared_ptr<::external::ipa::ProviderSelectionStrategyList>
        providerSelectionStrategy =
            std::make_shared<::external::ipa::ProviderSelectionStrategyList>();
    std::shared_ptr<::external::ipa::LanguageMatchingProviderSelectionStrategy>
        languageProviderSelectionStrategy = std::make_shared<
            ::external::ipa::LanguageMatchingProviderSelectionStrategy>();
    providerSelectionStrategy->addStrategy(languageProviderSelectionStrategy);
    std::shared_ptr<::external::ipa::ModalityMatchingProviderSelectionStrategy>
        modalityProviderSelectionStrategy =
        std::make_shared<::external::ipa::ModalityMatchingProviderSelectionStrategy>();
    providerSelectionStrategy->addStrategy(modalityProviderSelectionStrategy);

    // create main components in the external layer
    std::shared_ptr<ProviderRegistry> registry =
        std::make_shared<ProviderRegistry>(providerSelectionStrategy);
    std::shared_ptr<IPAProvider> chatGPT =
        std::make_shared<::reference::external::ipa::chatgpt::ChatGPTIPAProvider>();
    registry->addIPAProvider(chatGPT);
    std::shared_ptr<external::ProviderSelectionService> providerSelectionService =
        std::make_shared<external::ProviderSelectionService>(registry);

    // Create a processing chain
    console >> interactionManager >> ipaService >> providerSelectionService
            >> ipaDialogManager >> ipaService >> interactionManager;

    // Start capturing input
    interactionManager->start();
    interactionManager->waitExit();
    return 0;
}
