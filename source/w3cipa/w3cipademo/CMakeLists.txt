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

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
)

set(SOURCES
    src/main.cpp
)

source_group("W3C IPA Demo" FILES ${SOURCES} ${HEADERS})

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS})
target_link_libraries(${PROJECT_NAME} w3cipachatgptipaprovider)
target_link_libraries(${PROJECT_NAME} w3cipareferenceimplementation)
target_link_libraries(${PROJECT_NAME} w3cipaframework)

install(
  TARGETS ${PROJECT_NAME} 
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties DESTINATION config)
install(DIRECTORY ${W3CIPA_OPEN_SOURCE_SRC}/bin/ DESTINATION bin)

#
# Add configuration files
#
set(PROJECT_CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR}/config)
file(MAKE_DIRECTORY ${PROJECT_CONFIG_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/log4cplus.properties
    ${PROJECT_CONFIG_DIR}/log4cplus.properties COPYONLY)



