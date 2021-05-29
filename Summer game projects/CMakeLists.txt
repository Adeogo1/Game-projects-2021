cmake_minimum_required(VERSION 3.19)
project(Summer_game_projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(Summer_game_projects Initializations/main.cpp Initializations/HelloGL.cpp Initializations/HelloGL.h Initializations/GLUTCallbacks.cpp Initializations/GLUTCallbacks.h ArtificialDataTypes/Structs.h ArtificialDataTypes/Constants.h Draw2DShapes/Draw2D.cpp Draw2DShapes/Draw2D.h ArtificialDataTypes/Vector3.h ArtificialDataTypes/Camera.h)
target_link_libraries(Summer_game_projects -lOpenGL32 -lfreeGLUT -lglu32)