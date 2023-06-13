cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(w3cipa SHARED
  ClientInput.cpp
)

target_compile_definitions(w3cipa PRIVATE W3CIPA_LIBRARY)
