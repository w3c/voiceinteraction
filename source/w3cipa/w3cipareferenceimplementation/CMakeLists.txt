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

project(w3cipareferenceimplementation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    include/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h
    include/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h
    include/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h
    include/w3c/voiceinteraction/ipa/reference/IntegerRequestId.h
    include/w3c/voiceinteraction/ipa/reference/TextMultiModalInput.h
    include/w3c/voiceinteraction/ipa/reference/TextMultiModalOutput.h
    include/w3c/voiceinteraction/ipa/reference/UUIDSessionId.h
)

set(SOURCES
    src/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.cpp
    src/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.cpp
    src/w3c/voiceinteraction/ipa/reference/IntegerRequestId.cpp
    src/w3c/voiceinteraction/ipa/reference/TextMultiModalInput.cpp
    src/w3c/voiceinteraction/ipa/reference/TextMultiModalOutput.cpp
    src/w3c/voiceinteraction/ipa/reference/UUIDSessionId.cpp
)

source_group("W3C IPA Reference Implementation" FILES ${SOURCES} ${HEADERS})

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipaframework)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
