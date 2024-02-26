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
pkg_check_modules(PC_STDUUID QUIET stduuid)

find_path(STDUUID_INCLUDE_DIR
  NAMES
    uuid.h
  PATHS
    /usr/local/include
    /usr/include
    /opt/local/include
    /opt/csw/include
    /opt/include
    ${OPEN_SRC_INSTALL_PREFIX}/include
)

if(STDUUID_INCLUDE_DIR)
  set(STDUUID_INCLUDE_DIR ${STDUUID_INCLUDE_DIR} CACHE STRING "stduuid headers")
  message("found stduuid.")
endif()

include(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set STDUUID_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(stduuid DEFAULT_MSG STDUUID_INCLUDE_DIR)

MARK_AS_ADVANCED(STDUUID_INCLUDE_DIR)
