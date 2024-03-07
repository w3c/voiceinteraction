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

include_directories(${CMAKE_SOURCE_DIR}/w3cipaframework/include)

file(GLOB_RECURSE SOURCE
    "*.cpp"
    "*.h"
)
source_group("W3C Reference Implementation" FILES ${SOURCE})

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/w3cipaframework/include)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})

#
# Add configuration files
#
set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties
    ${PROJECT_CONFIG_DIR}/log4cplus.properties COPYONLY)


