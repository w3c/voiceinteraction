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

#include <iostream>
#include <thread>

#include <log4cplus/loggingmacros.h>

#include <w3c/voiceinteraction/ipa/TextModalityType.h>

#include "w3c/voiceinteraction/ipa/reference/TextMultiModalData.h"
#include "w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h"

namespace w3c {
namespace voiceinteraction {
namespace ipa {
namespace reference {
namespace client {

const ModalityType ConsoleTextModalityComponent::MODALITY = TextModalityType();
const log4cplus::Logger ConsoleTextModalityComponent::LOGGER =
    log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(
        "w3c.voiceinteraction.ipa.dialog.ConsoleTextModalityComponent"));

ConsoleTextModalityComponent::ConsoleTextModalityComponent()
    : ModalityComponent(MODALITY) {
}

const std::list<IOType> ConsoleTextModalityComponent::getSupportedIOTypes() const {
    std::list<IOType> types = {IOType::INPUT, IOType::OUTPUT };
    return types;
}

void ConsoleTextModalityComponent::startInput(const std::shared_ptr<InputNotificationMediator> &mediator) {
    std::thread thread([this, mediator] {
        captureInputAsynchronously(mediator);
    });
    thread.detach();
}

void ConsoleTextModalityComponent::captureInputAsynchronously(
    std::shared_ptr<InputNotificationMediator> mediator) {
    std::cout << "User: ";
    std::cout.flush();
    LOG4CPLUS_INFO(LOGGER, LOG4CPLUS_TEXT("Input started"));
    std::string input;
    std::getline(std::cin, input);
    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("User entered: %s"),
                       input.c_str());
    // TODO: get language from user or configuration
    Language language("en");
    std::shared_ptr<MultiModalData> multiModalInput =
        std::make_shared<TextMultiModalInput>(input, language);
    mediator->notifyListeners(multiModalInput);
}

void ConsoleTextModalityComponent::stopInput() {
    LOG4CPLUS_INFO(LOGGER, LOG4CPLUS_TEXT("Input started"));
}

void ConsoleTextModalityComponent::handleOutput(
    const std::shared_ptr<MultiModalData>& output) {
    std::shared_ptr<TextMultiModalInput> textOutput =
        std::dynamic_pointer_cast<TextMultiModalInput>(output);
    const std::string& text = textOutput->getText();
    std::cout << "System: " << text.c_str() << std::endl;
    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("Received response from ChatGPT: %s"),
                       text.c_str());
}

} // namespace client
} // namespace reference
} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c
