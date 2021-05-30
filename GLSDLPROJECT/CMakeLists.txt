cmake_minimum_required(VERSION 3.19)
project(GLSDLPROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLSDLPROJECT main.cpp)
target_link_libraries(GLSDLPROJECT -lOpenGL32 -lfreeGLUT )