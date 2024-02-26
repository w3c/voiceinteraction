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

file(GLOB_RECURSE w3cIPAFramework
        RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_SOURCE_DIR}/include/*.h*"
)
source_group("W3C IPA Framework" FILES ${w3cIPAFramework})
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB projectSRC
    "*.cpp"
    "*.h"
)
source_group("Reference Implementation" FILES ${projectSRC})

add_executable(${PROJECT_NAME} ${projectSRC}  ${w3cIPAFramework})
add_subdirectory(w3c/voiceinteraction/ipa)
add_subdirectory(w3c/voiceinteraction/ipa/client)
add_subdirectory(w3c/voiceinteraction/ipa/external/providerselectionservice)
add_subdirectory(w3c/voiceinteraction/ipa/external/ipa/chatgpt)
target_link_libraries(${PROJECT_NAME} ${requiredlibs})

set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties
    ${PROJECT_CONFIG_DIR}/log4cplus.properties COPYONLY)


