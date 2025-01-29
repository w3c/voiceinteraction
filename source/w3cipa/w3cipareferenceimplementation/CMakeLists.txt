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
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(HEADERS
    include/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.h
    include/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.h
    include/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.h
    include/w3c/voiceinteraction/ipa/reference/dialog/ReferenceDialogManager.h
    include/w3c/voiceinteraction/ipa/reference/IntegerRequestId.h
    include/w3c/voiceinteraction/ipa/reference/TextMultiModalData.h
    include/w3c/voiceinteraction/ipa/reference/UUIDSessionId.h
)

set(SOURCES
    src/w3c/voiceinteraction/ipa/reference/client/ConsoleTextModalityComponent.cpp
    src/w3c/voiceinteraction/ipa/reference/client/TakeFirstInputModalityComponentListener.cpp
    src/w3c/voiceinteraction/ipa/reference/dialog/ReferenceIPAService.cpp
    src/w3c/voiceinteraction/ipa/reference/dialog/ReferenceDialogManager.cpp
    src/w3c/voiceinteraction/ipa/reference/IntegerRequestId.cpp
    src/w3c/voiceinteraction/ipa/reference/TextMultiModalData.cpp
    src/w3c/voiceinteraction/ipa/reference/UUIDSessionId.cpp
)

source_group("W3C IPA Reference Implementation" FILES ${SOURCES} ${HEADERS})

add_library(${PROJECT_NAME} ${W3CIPA_BUILD_SHARED_LIBS} ${SOURCES} ${HEADERS})
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} 
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}/include 
    FILES ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipaframework)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(TARGETS ${PROJECT_NAME} FILE_SET HEADERS)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/w3cipareferenceimplementation_export.h
    DESTINATION include)
install(DIRECTORY doc/ DESTINATION doc)

