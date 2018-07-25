cmake_minimum_required(VERSION 3.8)
project(boring_runner)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(include)
link_directories(lib)

set(SOURCE_FILES main.cpp include/utilities.hpp include/Entity.hpp include/Point2D.hpp src/Point2D.cpp include/SpriteSheet.hpp src/SpriteSheet.cpp src/utilities.cpp include/Game.hpp src/Game.cpp include/AssetsManager.hpp src/AssetsManager.cpp include/Timer.hpp src/Timer.cpp include/World.hpp include/Renderable.hpp include/WorldLayer.hpp)

add_executable(boring_runner ${SOURCE_FILES})

target_link_libraries(boring_runner mingw32 SDL2main SDL2 SDL2_image)