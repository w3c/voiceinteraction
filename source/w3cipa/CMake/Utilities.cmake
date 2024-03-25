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

if(NOT OPEN_SRC_INSTALL_PREFIX OR OPEN_SRC_INSTALL_PREFIX STREQUAL "")
  set(OPEN_SRC_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/open-source" CACHE PATH "Libraries will be downloaded and built in this directory.")
else()
  set(OPEN_SRC_INSTALL_PREFIX ${OPEN_SRC_INSTALL_PREFIX} CACHE PATH "Libraries will be downloaded and built in this directory.")
endif()
message(STATUS "Libraries will be downloaded and built in ${OPEN_SRC_INSTALL_PREFIX}")

# only fetch target repo for add_subdirectory later
function(fetch_repo lib_name)
  set(supported_libs
      w3cipaproducer)
  list(FIND supported_libs ${lib_name} index)
  if(${index} EQUAL -1)
    message(WARNING "${lib_name} is not supported for fetch_repo")
    return()
  endif()

  # build library
  configure_file(
    ./CMake/Dependencies/lib${lib_name}-CMakeLists.txt
    ${DEPENDENCY_DOWNLOAD_PATH}/lib${lib_name}/CMakeLists.txt COPYONLY)
  execute_process(
    COMMAND ${CMAKE_COMMAND}
            ${CMAKE_GENERATOR} .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${DEPENDENCY_DOWNLOAD_PATH}/lib${lib_name})
  if(result)
    message(FATAL_ERROR "CMake step for lib${lib_name} failed: ${result}")
  endif()
  execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${DEPENDENCY_DOWNLOAD_PATH}/lib${lib_name})
  if(result)
    message(FATAL_ERROR "CMake step for lib${lib_name} failed: ${result}")
  endif()
endfunction()

# build library from source
function(build_dependency lib_name)
  set(supported_libs
      log4cplus
      nlohmann_json
      openssl
      curl
      stduuid)
  set(header_only_libs
      nlohmann_json
      stduuid)
  list(FIND supported_libs ${lib_name} index)
  if(${index} EQUAL -1)
    message(WARNING "${lib_name} is not supported to build from source")
    return()
  endif()

  set(target_found NOTFOUND)
  set(header_found NOTFOUND)

  if (${lib_name} STREQUAL "autoconf" OR ${lib_name} STREQUAL "automake")
    find_program(
      target_found
      NAMES ${lib_name}
      PATHS ${OPEN_SRC_INSTALL_PREFIX}/bin
      NO_DEFAULT_PATH)
  else()
    set(lib_file_name ${lib_name})
    set(header_file_name ${lib_name})
    if (${lib_name} STREQUAL "openssl")
      set(lib_file_name ssl)
    endif()

    list(FIND header_only_libs ${lib_name} index)
    if(NOT ${index} EQUAL -1)
        if (${header_file_name} STREQUAL "nlohmann_json")
          set(header_file_name "nlohmann")
        endif()
        if (${header_file_name} STREQUAL "stduuid")
          set(header_file_name "uuid.h")
        endif()

        find_path(header_found
            NAMES ${header_file_name}
            PATHS ${OPEN_SRC_INSTALL_PREFIX}/include
            NO_DEFAULT_PATH)
    else()
        find_library(
          target_found
          NAMES ${lib_file_name}
          PATHS ${OPEN_SRC_INSTALL_PREFIX}/lib
          NO_DEFAULT_PATH)
    endif()
  endif()

  if(target_found OR header_found)
    message(STATUS "${lib_name} already built")
    return()
  endif()

  # anything after lib_name(${ARGN}) are assumed to be arguments passed over to
  # library building cmake.
  set(build_args ${ARGN})

  file(REMOVE_RECURSE ${W3CIPA_OPEN_SOURCE_SRC}/lib${lib_name})

  # build library
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Dependencies/lib${lib_name}-CMakeLists.txt
    ${W3CIPA_OPEN_SOURCE_SRC}/lib${lib_name}/CMakeLists.txt COPYONLY)
  execute_process(
    COMMAND ${CMAKE_COMMAND} ${build_args}
            -DOPEN_SRC_INSTALL_PREFIX=${OPEN_SRC_INSTALL_PREFIX} -G
            ${CMAKE_GENERATOR} .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${W3CIPA_OPEN_SOURCE_SRC}/lib${lib_name})
  if(result)
    message(FATAL_ERROR "CMake step for lib${lib_name} failed: ${result}")
  endif()
  execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${W3CIPA_OPEN_SOURCE_SRC}/lib${lib_name})
  if(result)
    message(FATAL_ERROR "CMake step for lib${lib_name} failed: ${result}")
  endif()

  file(REMOVE_RECURSE ${W3CIPA_OPEN_SOURCE_SRC}/lib${lib_name})
endfunction()

function(enableSanitizer SANITIZER)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -fsanitize=${SANITIZER} -fno-omit-frame-pointer" PARENT_SCOPE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -fsanitize=${SANITIZER} -fno-omit-frame-pointer -fno-optimize-sibling-calls" PARENT_SCOPE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=${SANITIZER}" PARENT_SCOPE)
endfunction()
