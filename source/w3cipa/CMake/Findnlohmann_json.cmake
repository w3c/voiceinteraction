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
find_package(PkgConfig)
pkg_check_modules(PC_NLOHMANN_JSON QUIET nlohmann_json)

find_path(NLOHMANN_JSON_INCLUDE_DIR
  NAMES
    json.hpp
  PATH_PREFIXES
    nlohmann
  PATHS
    /usr/local/include
    /usr/include
    /opt/local/include
    /opt/csw/include
    /opt/include
    ${OPEN_SRC_INSTALL_PREFIX}/include
)

if(NLOHMANN_JSON_INCLUDE_DIR)
  set(NLOHMANN_JSON_INCLUDE_DIR ${NLOHMANN_JSON_INCLUDE_DIR} CACHE STRING "nlohmann_json headers")
  message("found nlohmann_json.")
endif()

include(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set NLOHMANN_JSON_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(nlohmann_json DEFAULT_MSG NLOHMANN_JSON_INCLUDE_DIR)

MARK_AS_ADVANCED(NLOHMANN_JSON_INCLUDE_DIR)
