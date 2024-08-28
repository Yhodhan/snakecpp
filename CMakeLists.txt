cmake_minimum_required(VERSION 2.8)
project(snake)

set(CXXFLAGS  "-std=c++17 -g -Werror -Wall")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_NAME} ${SDL_INCLUDE_DIRS})

file(GLOB SOURCE_FILES src/*.cpp src/context/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
