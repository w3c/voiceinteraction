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

project(w3cipaframework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE w3cIPAFramework
    "*.cpp"
    "*.h"
)
source_group("W3C IPA Framework" FILES ${w3cIPAFramework})

#add_library(${PROJECT_NAME} ${w3cIPAFramework})
#
#install(TARGETS ${PROJECT_NAME}
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION lib)
