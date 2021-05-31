cmake_minimum_required(VERSION 3.19)
project(GLSDLProject1pt2)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(GLSDLProject1pt2 main.cpp Engine/Engine.cpp Engine/Engine.h DataTypes/Structs.h DataTypes/Constants.h Engine/Timer.cpp Engine/Timer.h InputManager/InputManager.cpp InputManager/InputManager.h Actor.cpp Actor.h Character.cpp Character.h DataTypes/Collider.cpp DataTypes/Collider.h GameObject.cpp GameObject.h DataTypes/Component.cpp DataTypes/Component.h)
target_link_libraries(${PROJECT_NAME} SDL2_image SDL2main SDL2)
target_link_libraries(GLSDLProject1pt2 -lOpenGL32 -lfreeGLUT -lglu32 -lglew32)