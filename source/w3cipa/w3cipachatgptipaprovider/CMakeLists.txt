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

project(w3cipachatgptipaprovider LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(HEADERS
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTMessage.h
)

set(SOURCES
    src/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.cpp
)

source_group("W3C IPA ChatGPT IPAProvider" FILES ${SOURCES} ${HEADERS})

include_directories(include)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}/include 
    FILES ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipareferenceimplementation)
target_link_libraries(${PROJECT_NAME} w3cipaframework)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ChatGPTIPAProvider.json DESTINATION config)
install(TARGETS ${PROJECT_NAME} FILE_SET HEADERS)
install(DIRECTORY doc/ DESTINATION doc)
