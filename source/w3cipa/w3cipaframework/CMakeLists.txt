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

cmake_minimum_required(VERSION 3.22)

project(w3cipaframework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(HEADERS
    include/w3c/voiceinteraction/ipa/AudioData.h
    include/w3c/voiceinteraction/ipa/AudioDeliveryType.h
    include/w3c/voiceinteraction/ipa/AudioEncoding.h
    include/w3c/voiceinteraction/ipa/CallResult.h
    include/w3c/voiceinteraction/ipa/ClientRequest.h
    include/w3c/voiceinteraction/ipa/ClientResponse.h
    include/w3c/voiceinteraction/ipa/CombinedId.h
    include/w3c/voiceinteraction/ipa/DialogManager.h
    include/w3c/voiceinteraction/ipa/ErrorMessage.h
    include/w3c/voiceinteraction/ipa/ExternalClientResponse.h
    include/w3c/voiceinteraction/ipa/IPAData.h
    include/w3c/voiceinteraction/ipa/IPADataProcessor.h
    include/w3c/voiceinteraction/ipa/Language.h
    include/w3c/voiceinteraction/ipa/LanguageDependent.h
    include/w3c/voiceinteraction/ipa/MetaData.h
    include/w3c/voiceinteraction/ipa/ModalityType.h
    include/w3c/voiceinteraction/ipa/MultiModalInput.h
    include/w3c/voiceinteraction/ipa/MultiModalInputs.h
    include/w3c/voiceinteraction/ipa/MultiModalOutput.h
    include/w3c/voiceinteraction/ipa/MultiModalOutputs.h
    include/w3c/voiceinteraction/ipa/RequestId.h
    include/w3c/voiceinteraction/ipa/SemanticInterpretation.h
    include/w3c/voiceinteraction/ipa/SessionId.h
    include/w3c/voiceinteraction/ipa/TextModalityType.h
    include/w3c/voiceinteraction/ipa/Timestamp.h
    include/w3c/voiceinteraction/ipa/VoiceModalityType.h
    include/w3c/voiceinteraction/ipa/client/InputModalityComponent.h
    include/w3c/voiceinteraction/ipa/client/InputModalityComponentListener.h
    include/w3c/voiceinteraction/ipa/client/InputNotificationMediator.h
    include/w3c/voiceinteraction/ipa/client/IOType.h
    include/w3c/voiceinteraction/ipa/client/ModalityComponent.h
    include/w3c/voiceinteraction/ipa/client/ModalityManager.h
    include/w3c/voiceinteraction/ipa/client/OutputModalityComponent.h
    include/w3c/voiceinteraction/ipa/dialog/IPAService.h
    include/w3c/voiceinteraction/ipa/external/ProviderSelectionService.h
    include/w3c/voiceinteraction/ipa/external/ipa/IPAProvider.h
    include/w3c/voiceinteraction/ipa/external/ipa/LanguageMatchingProviderSelectionStrategy.h
    include/w3c/voiceinteraction/ipa/external/ipa/ModalityMatchingProviderSelectionStrategy.h
    include/w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.h
    include/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.h
    include/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategyList.h)

set(SOURCES
    src/w3c/voiceinteraction/ipa/ClientRequest.cpp
    src/w3c/voiceinteraction/ipa/ClientResponse.cpp
    src/w3c/voiceinteraction/ipa/CombinedId.cpp
    src/w3c/voiceinteraction/ipa/DialogManager.cpp
    src/w3c/voiceinteraction/ipa/ModalityType.cpp
    src/w3c/voiceinteraction/ipa/ErrorMessage.cpp
    src/w3c/voiceinteraction/ipa/ExternalClientResponse.cpp
    src/w3c/voiceinteraction/ipa/IPAData.cpp
    src/w3c/voiceinteraction/ipa/IPADataProcessor.cpp
    src/w3c/voiceinteraction/ipa/Language.cpp
    src/w3c/voiceinteraction/ipa/Metadata.cpp
    src/w3c/voiceinteraction/ipa/MultiModalInput.cpp
    src/w3c/voiceinteraction/ipa/MultiModalInputs.cpp
    src/w3c/voiceinteraction/ipa/MultiModalOutput.cpp
    src/w3c/voiceinteraction/ipa/MultiModalOutputs.cpp
    src/w3c/voiceinteraction/ipa/RequestId.cpp
    src/w3c/voiceinteraction/ipa/SessionId.cpp
    src/w3c/voiceinteraction/ipa/TextModalityType.cpp
    src/w3c/voiceinteraction/ipa/Timestamp.cpp
    src/w3c/voiceinteraction/ipa/VoiceModalityType.cpp
    src/w3c/voiceinteraction/ipa/client/InputModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/client/InputModalityComponentListener.cpp
    src/w3c/voiceinteraction/ipa/client/InputNotificationMediator.cpp
    src/w3c/voiceinteraction/ipa/client/ModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/client/ModalityManager.cpp
    src/w3c/voiceinteraction/ipa/client/OutputModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/dialog/IPAService.cpp
    src/w3c/voiceinteraction/ipa/external/ProviderSelectionService.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/IPAProvider.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/LanguageMatchingProviderSelectionStrategy.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ModalityMatchingProviderSelectionStrategy.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategyList.cpp)

source_group("W3C IPA Framework" FILES ${SOURCES} ${HEADERS})

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
# check if Doxygen is installed
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../../docs/framework-doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        # request to configure the file
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")

        # note the option ALL which allows to build the docs together with the application
        add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
    else (DOXYGEN_FOUND)
      message("Doxygen need to be installed to generate the doxygen documentation")
    endif (DOXYGEN_FOUND)
endif()
