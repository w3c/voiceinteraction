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
