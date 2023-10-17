cmake_minimum_required(VERSION 3.14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")
include(Utilities)

project(w3cipa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(W3CIPA_OPEN_SOURCE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/open-source)

message(STATUS "dependencies install path is ${W3CIPA_OPEN_SOURCE_SRC}")

build_dependency(log4cplus -DBUILD_STATIC=${BUILD_STATIC})

find_package(PkgConfig REQUIRED)

#if (WIN32)
#  find_package(Log4cplus
#    NAMES log4cplus REQUIRED
#    PATHS ${OPEN_SRC_INSTALL_PREFIX}/lib)
#  SET(Log4cplus "log4cplus::log4cplus")
#else()
  find_package(Log4cplus REQUIRED)
  include_directories(${LOG4CPLUS_INCLUDE_DIR})
  set(Log4cplus ${LOG4CPLUS_LIBRARIES})
#endif()

add_subdirectory(sources)
