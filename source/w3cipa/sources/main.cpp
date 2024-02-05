#include <string>
#include <memory>

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include "w3c/voiceinteraction/ipa/textmultimodalinput.h"
#include "w3c/voiceinteraction/ipa/textmultimodaloutput.h"
#include "w3c/voiceinteraction/ipa/dialog/referenceipaservice.h"
#include "w3c/voiceinteraction/ipa/external/providerselectionservice/referenceproviderselectionservice.h"

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
    std::shared_ptr<w3c::voiceinteraction::ipa::external::providerselectionservice::ReferenceProviderSelectionService> providerSelectionService =
        std::make_shared<w3c::voiceinteraction::ipa::external::providerselectionservice::ReferenceProviderSelectionService>();
    w3c::voiceinteraction::ipa::dialog::ReferenceIPAService ipaService(providerSelectionService);

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
    std::shared_ptr<TextMultiModalOutput> textOutput =
        std::dynamic_pointer_cast<TextMultiModalOutput>(output);
    LOG4CPLUS_INFO_FMT(LOGGER,
                       LOG4CPLUS_TEXT("Received response from ChatGPT: %s"),
                       textOutput->getTextOutput().c_str());

    return 0;
}
