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
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")

include(FindPkgConfig)
include(FetchContent)
include(Utilities)

project(w3cipa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# User Flags
option(BUILD_W3CIPA_DOC "Build documentation" ON)
option(BUILD_W3CIPA_DEPENDENCIES "Whether or not to build depending libraries from source" ON)

#
# Adapt the install path for dependent libs
#
set(W3CIPA_OPEN_SOURCE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/open-source)
set(ENV{PKG_CONFIG_PATH}
          "$ENV{PKG_CONFIG_PATH}:${OPEN_SRC_INSTALL_PREFIX}/lib/pkgconfig")
set(ENV{PATH} "$ENV{PATH}:${W3CIPA_OPEN_SOURCE_SRC}/bin")

#
# Build dependent libraries
#
if (BUILD_W3CIPA_DEPENDENCIES)
    message(STATUS "Begin building dependencies.")
    build_dependency(log4cplus -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS})
    build_dependency(nlohmann_json)
    if (WIN32)
        file(COPY ${CURL_SHARED_LIBRARY} DESTINATION ${W3CIPA_OPEN_SOURCE_SRC}/bin)
    else()
        build_dependency(openssl)
        build_dependency(curl)
    endif()
    build_dependency(stduuid)
    message(STATUS "Finished building dependencies.")
endif()

#
# Find required libraries
#

find_package(PkgConfig REQUIRED)
find_package(Log4cplus REQUIRED)
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(stduuid REQUIRED)

#
# Add settings to the build envionment
#
include_directories(${LOG4CPLUS_INCLUDE_DIR})
set(Log4cplus ${LOG4CPLUS_LIBRARIES})
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${Log4cplus})

include_directories(${nlohmann_json_SOURCE_DIR}/include)
include_directories(${CURL_INCLUDE_DIR})
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${CURL_LIBRARIES})

message(STATUS ${CURL_LIBRARIES})


include_directories(${NLOHMANN_JSON_INCLUDE_DIR})

include_directories(${STDUUID_INCLUDE_DIR})

#
# Prepare configuration folder
#
set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/w3cipademo/config)
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})

#
# W3C IPA Framework and Reference Implementation
#

add_subdirectory(w3cipaframework)
add_subdirectory(w3cipachatgptipaprovider)
add_subdirectory(w3cipareferenceimplementation)
add_subdirectory(w3cipademo)

