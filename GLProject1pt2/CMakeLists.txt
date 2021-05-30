cmake_minimum_required(VERSION 3.19)
project(GLProject1)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLProject1 Initializations/main.cpp Initializations/HelloGL.cpp Initializations/HelloGL.h Initializations/GLUTCallbacks.cpp Initializations/GLUTCallbacks.h ArtificialDataTypes/Structs.h ArtificialDataTypes/Constants.h Draw2DShapes/Draw2D.cpp Draw2DShapes/Draw2D.h ArtificialDataTypes/Vector3.h ArtificialDataTypes/Camera.h)
target_link_libraries(GLProject1 -lOpenGL32 -lfreeGLUT -lSDL2)