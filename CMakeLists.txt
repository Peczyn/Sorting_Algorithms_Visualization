cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES main.cpp)

add_executable(sorting_algorithms ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sorting_algorithms sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


