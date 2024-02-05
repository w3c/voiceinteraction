cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB projectSRC
    "*.cpp"
    "*.h"
)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(w3c/voiceinteraction/ipa)
add_subdirectory(w3c/voiceinteraction/ipa/dialog)
add_subdirectory(w3c/voiceinteraction/ipa/external/providerselectionservice)
add_subdirectory(w3c/voiceinteraction/ipa/external/ipa/chatgpt)
target_link_libraries(${PROJECT_NAME} ${requiredlibs})

set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
message(${PROJECT_CONFIG_DIR})
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties
    ${PROJECT_CONFIG_DIR}/log4cplus.properties COPYONLY)
