﻿#
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
    include/w3c/voiceinteraction/ipa/ClientInput.h
    include/w3c/voiceinteraction/ipa/ClientRequest.h
    include/w3c/voiceinteraction/ipa/ClientResponse.h
    include/w3c/voiceinteraction/ipa/ErrorMessage.h
    include/w3c/voiceinteraction/ipa/ExternalClientInput.h
    include/w3c/voiceinteraction/ipa/ExternalClientResponse.h
    include/w3c/voiceinteraction/ipa/MetaData.h
    include/w3c/voiceinteraction/ipa/ModalityType.h
    include/w3c/voiceinteraction/ipa/MultiModalInput.h
    include/w3c/voiceinteraction/ipa/MultiModalInputs.h
    include/w3c/voiceinteraction/ipa/MultiModalOutput.h
    include/w3c/voiceinteraction/ipa/MultiModalOutputs.h
    include/w3c/voiceinteraction/ipa/RequestId.h
    include/w3c/voiceinteraction/ipa/SemanticInterpretation.h
    include/w3c/voiceinteraction/ipa/SessionId.h
    include/w3c/voiceinteraction/ipa/Timestamp.h
    include/w3c/voiceinteraction/ipa/client/InputModalityComponent.h
    include/w3c/voiceinteraction/ipa/client/InputModalityComponentListener.h
    include/w3c/voiceinteraction/ipa/client/IOType.h
    include/w3c/voiceinteraction/ipa/client/ModalityComponent.h
    include/w3c/voiceinteraction/ipa/client/ModalityManager.h
    include/w3c/voiceinteraction/ipa/client/OutputModalityComponent.h
    include/w3c/voiceinteraction/ipa/external/ProviderSelectionService.h
    include/w3c/voiceinteraction/ipa/external/ipa/IPAProvider.h
    include/w3c/voiceinteraction/ipa/external/ipa/IPAService.h
    include/w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.h
    include/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.h
)

set(SOURCES
    src/w3c/voiceinteraction/ipa/ClientRequest.cpp
    src/w3c/voiceinteraction/ipa/ClientResponse.cpp
    src/w3c/voiceinteraction/ipa/ModalityType.cpp
    src/w3c/voiceinteraction/ipa/ErrorMessage.cpp
    src/w3c/voiceinteraction/ipa/ExternalClientResponse.cpp
    src/w3c/voiceinteraction/ipa/MultiModalInput.cpp
    src/w3c/voiceinteraction/ipa/MultiModalInputs.cpp
    src/w3c/voiceinteraction/ipa/MultiModalOutput.cpp
    src/w3c/voiceinteraction/ipa/MultiModalOutputs.cpp
    src/w3c/voiceinteraction/ipa/RequestId.cpp
    src/w3c/voiceinteraction/ipa/SessionId.cpp
    src/w3c/voiceinteraction/ipa/client/InputModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/client/InputModalityComponentListener.cpp
    src/w3c/voiceinteraction/ipa/client/ModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/client/ModalityManager.cpp
    src/w3c/voiceinteraction/ipa/client/OutputModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/external/ProviderSelectionService.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/IPAProvider.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/IPAService.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ProviderRegistry.cpp
    src/w3c/voiceinteraction/ipa/external/ipa/ProviderSelectionStrategy.cpp
)

source_group("W3C IPA Framework" FILES ${SOURCES} ${HEADERS})

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
