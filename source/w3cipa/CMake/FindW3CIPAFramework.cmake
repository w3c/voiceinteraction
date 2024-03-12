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

find_library(W3C_IPA_FRAMEWORK_LIBRARY
    NAMES
        w3cipaframework
    PATHS
        ${CMAKE_BINARY_DIR}/w3cipaframework
)
set(W3C_IPA_FRAMEWORK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/w3cipaframework/include/)
