#
# IPA Reference Implementation: https://github.com/w3c/voiceinteraction
#
# Copyright (C) 2024 World Wide Web Consortium. All Rights Reserved.
#
# This work is distributed under the W3C Software and Document License [1]
# in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# [1] https://www.w3.org/Consortium/Legal/copyright-software
#

cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    include/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h
    include/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h
    include/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTAdapter.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTMessage.h
    include/w3c/voiceinteraction/ipa/reference/external/providerselectionservice/ModalityMatchingProviderSelectionStrategy.h
    include/w3c/voiceinteraction/ipa/reference/IntegerRequestId.h
    include/w3c/voiceinteraction/ipa/reference/TextModalityType.h
    include/w3c/voiceinteraction/ipa/reference/TextMultiModalInput.h
    include/w3c/voiceinteraction/ipa/reference/TextMultiModalOutput.h
    include/w3c/voiceinteraction/ipa/reference/UUIDSessionId.h
)

set(SOURCES
    src/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.cpp
    src/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.cpp
    src/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTAdapter.cpp
    src/w3c/voiceinteraction/ipa/reference/external/providerselectionservice/ModalityMatchingProviderSelectionStrategy.cpp
    src/w3c/voiceinteraction/ipa/reference/IntegerRequestId.cpp
    src/w3c/voiceinteraction/ipa/reference/TextModalityType.cpp
    src/w3c/voiceinteraction/ipa/reference/TextMultiModalInput.cpp
    src/w3c/voiceinteraction/ipa/reference/TextMultiModalOutput.cpp
    src/w3c/voiceinteraction/ipa/reference/UUIDSessionId.cpp
    src/main.cpp
)

source_group("W3C IPA Reference Implementation" FILES ${SOURCES} ${HEADERS})

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipaframework)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

#
# Add configuration files
#
set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties
    ${PROJECT_CONFIG_DIR}/log4cplus.properties COPYONLY)


