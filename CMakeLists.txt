cmake_minimum_required(VERSION 3.16)
project(SpaceTour_)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpaceTour_ main.cpp OpenSpace.cpp OpenSpace.h ScreenController.cpp ScreenController.h Falcon_9.cpp Falcon_9.h Enemy.cpp Enemy.h Enemies.cpp Enemies.h)

add_compile_options(-Wall -Wextra)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SpaceTour_ sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
