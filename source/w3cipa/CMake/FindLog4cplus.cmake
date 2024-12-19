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

#-------------------------------------------------------------------------------------
# Locate Log4cplus library
# This module defines
#    LOG4CPLUS_FOUND, if false, do not try to link to Log4cplus
#    LOG4CPLUS_LIBRARIES
#    LOG4CPLUS_INCLUDE_DIR, where to find log4cplus headers
#
# Original script was picked up here
#    https://github.com/snikulov/cmake-modules/blob/master/FindLog4cplus.cmake
#
#-------------------------------------------------------------------------------------

find_package(PkgConfig)
pkg_check_modules(PC_LOG4CPLUS QUIET log4cplus)

find_path(LOG4CPLUS_INCLUDE_DIR
  NAMES
    logger.h
  PATH_PREFIXES
    log4cplus
  PATHS
    /usr/local/include
    /usr/include
    /opt/local/include
    /opt/csw/include
    /opt/include
    /include
    /{<CONFIG>_OUTPUT_NAME}/include
    $ENV{LOG4CPLUS_DIR}/include
    $ENV{LOG4CPLUS_ROOT}/include
    ${LOG4CPLUS_DIR}/include
    ${LOG4CPLUS_ROOT}/include
  HINTS
    ${PC_LOG4CPLUS_INCLUDE_DIR}
    ${PC_LOG4CPLUS_INCLUDE_DIRS}
)

find_library(LOG4CPLUS_LIBRARY
  NAMES
    log4cplus
    log4cplusD
  PATHS
    /usr/local
    /usr
    /sw
    /opt/local
    /opt/csw
    /opt
    /lib
    ${W3CIPA_OPEN_SOURCE_SRC}/lib
    $ENV{LOG4CPLUS_DIR}/lib
    $ENV{LOG4CPLUS_ROOT}/lib
    ${LOG4CPLUS_DIR}/lib
    ${LOG4CPLUS_ROOT}/lib
  HINTS
    ${PC_LOG4CPLUS_LIBDIR}
    ${PC_LOG4CPLUS_LIBRARY_DIRS}
)

if(LOG4CPLUS_LIBRARY)
  set(LOG4CPLUS_LIBRARIES ${LOG4CPLUS_LIBRARY} CACHE STRING "Log4cplus Libraries")
  message("-- found log4cplus.")
endif()

include(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set LOG4CPLUS_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Log4cplus DEFAULT_MSG LOG4CPLUS_LIBRARY LOG4CPLUS_INCLUDE_DIR)

MARK_AS_ADVANCED(LOG4CPLUS_INCLUDE_DIR LOG4CPLUS_LIBRARY)
