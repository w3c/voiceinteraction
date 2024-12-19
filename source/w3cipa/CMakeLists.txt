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
option(BUILD_W3CIPA_DOC "Build documentation" OFF)
option(BUILD_W3CIPA_DEPENDENCIES "Whether or not to build depending libraries from source" ON)

#
# Adapt the install path for dependent libs
#
set(W3CIPA_OPEN_SOURCE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/open-source)
set(ENV{PKG_CONFIG_PATH}
          "$ENV{PKG_CONFIG_PATH}:${W3CIPA_OPEN_SOURCE_SRC}/lib/pkgconfig")
set(ENV{PATH} "$ENV{PATH}:${W3CIPA_OPEN_SOURCE_SRC}/bin")

#
# Build dependent libraries
#
if (BUILD_W3CIPA_DEPENDENCIES)
    message(STATUS "Begin building dependencies.")
    build_dependency(log4cplus -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS})
    build_dependency(nlohmann_json)
    if (!WIN32)
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
find_package(Log4cplus MODULE REQUIRED)
# On Windows we are relying on VCPKG to download CURL.
if (WIN32)
    find_package(CURL MODULE REQUIRED)
else()
    find_package(CURL CONFIG REQUIRED PATHS ${W3CIPA_OPEN_SOURCE_SRC})
endif()
find_package(nlohmann_json CONFIG REQUIRED PATHS ${W3CIPA_OPEN_SOURCE_SRC})
find_package(stduuid REQUIRED PATHS ${W3CIPA_OPEN_SOURCE_SRC})

#
# Add settings to the build envionment
#
include_directories(${LOG4CPLUS_INCLUDE_DIR})
set(REQUIRED_LIBS ${REQUIRED_LIBS} ${LOG4CPLUS_LIBRARY})

set(REQUIRED_LIBS ${REQUIRED_LIBS} CURL::libcurl)
set(REQUIRED_LIBS ${REQUIRED_LIBS} nlohmann_json::nlohmann_json)

message(STATUS "REQUIRED_LIBS: ${REQUIRED_LIBS}")

include_directories(${STDUUID_INCLUDE_DIR})

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

