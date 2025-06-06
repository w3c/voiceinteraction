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

# Enable VCPKG Toolchain
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(w3cipa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# User Flags
option(BUILD_W3CIPA_DOC "Build documentation" OFF)
option(BUILD_W3CIPA_DEPENDENCIES "Whether or not to build depending libraries from source" ON)
option(BUILD_W3CIPA_SHARED "Wether or not to build shared libraries" OFF)

#
# Set internally shared or static
#
if (BUILD_W3CIPA_SHARED)
    set(W3CIPA_BUILD_SHARED_LIBS SHARED)
    message(STATUS "Building W3CIPA shared libraries")
else()
    set(W3CIPA_BUILD_SHARED_LIBS STATIC)
    message(STATUS "Building W3CIPA static libraries")
endif()


#
# Find required libraries
#
if (UNIX)
    include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
endif()

find_package(CURL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(log4cplus CONFIG REQUIRED)
find_package(stduuid CONFIG REQUIRED)

#
# Add settings to the build envionment
#
set(REQUIRED_LIBS ${REQUIRED_LIBS} log4cplus::log4cplus)
set(REQUIRED_LIBS ${REQUIRED_LIBS} CURL::libcurl)
set(REQUIRED_LIBS ${REQUIRED_LIBS} nlohmann_json::nlohmann_json)
set(REQUIRED_LIBS ${REQUIRED_LIBS} stduuid)

message(STATUS "REQUIRED_LIBS: ${REQUIRED_LIBS}")

if (BUILD_W3CIPA_DOC)
# check if Doxygen is installed
    find_package(Doxygen)
    if (!DOXYGEN_FOUND)
      message("Doxygen need to be installed to generate the doxygen documentation")
      set(BUILD_W3CIPA_DOC OFF)
    endif()
endif()

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

