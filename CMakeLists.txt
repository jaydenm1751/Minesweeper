cmake_minimum_required(VERSION 3.23)
project(project3)

set(CMAKE_CXX_STANDARD 23)

add_executable(project3 main.cpp Tile.h TextureManager.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/include)
target_link_libraries(project3 sfml-system sfml-window sfml-graphics sfml-audio)
