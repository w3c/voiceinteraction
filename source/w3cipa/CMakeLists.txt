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
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")

include(FindPkgConfig)
include(FetchContent)
include(Utilities)

project(w3cipa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(W3CIPA_OPEN_SOURCE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/open-source)

message(STATUS "dependencies install path is ${W3CIPA_OPEN_SOURCE_SRC}")

#
# Build dependent libraries
#

build_dependency(log4cplus -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS})
build_dependency(nlohmann_json)
#build_dependency(openssl)
#build_dependency(curl)
build_dependency(stduuid)

#
# Find required libraris
#

find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)
find_package(Log4cplus REQUIRED)
find_package(stduuid REQUIRED)

#
# Special handling for nlohmann_json as stated on https://github.com/nlohmann/json/blob/develop/README.md#cmake
#

set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        nlohmann
        GIT_REPOSITORY  "https://github.com/nlohmann/json"
        GIT_TAG         "v3.9.1"
)
FetchContent_MakeAvailable(nlohmann)

#
# Add settings to the build envionment
#

include_directories(${LOG4CPLUS_INCLUDE_DIR})
set(Log4cplus ${LOG4CPLUS_LIBRARIES})
set(requiredlibs ${requiredlibs} ${Log4cplus})

include_directories(${nlohmann_json_SOURCE_DIR}/include)
include_directories(${CURL_INCLUDE_DIR})
set(requiredlibs ${requiredlibs} ${CURL_LIBRARIES})

include_directories(${STDUUID_INCLUDE_DIR})

add_subdirectory(sources)


