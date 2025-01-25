cmake_minimum_required(VERSION 3.22)

project(w3cipachatgptipaprovider LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(HEADERS
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTConfiguration.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTMessage.h
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPClient.h 
    include/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPException.h)

set(SOURCES
    src/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/ChatGPTIPAProvider.cpp
    src/w3c/voiceinteraction/ipa/reference/external/ipa/chatgpt/HTTPClient.cpp)

source_group("W3C IPA ChatGPT IPAProvider" FILES ${SOURCES} ${HEADERS})

include_directories(include)

add_library(${PROJECT_NAME} ${W3CIPA_BUILD_SHARED_LIBS} ${SOURCES} ${HEADERS})
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}/include 
    FILES ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipareferenceimplementation)
target_link_libraries(${PROJECT_NAME} w3cipaframework)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Download cacert.pem if it doesn't exist
set(CACERT_URL "https://curl.se/ca/cacert.pem")
set(CACERT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cacert.pem")

if(NOT EXISTS ${CACERT_FILE})
    message(STATUS "Downloading cacert.pem from ${CACERT_URL}")
    file(DOWNLOAD ${CACERT_URL} ${CACERT_FILE} SHOW_PROGRESS)
endif()

# Add configuration files
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ChatGPTIPAProvider.json
    ${PROJECT_CONFIG_DIR}/ChatGPTIPAProvider.json COPYONLY)
configure_file(${CACERT_FILE}
    ${PROJECT_CONFIG_DIR}/cacert.pem COPYONLY)

# Installation
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ChatGPTIPAProvider.json DESTINATION config)
install(FILES ${CACERT_FILE} DESTINATION config)
install(TARGETS ${PROJECT_NAME} FILE_SET HEADERS)
install(DIRECTORY doc/ DESTINATION doc)
