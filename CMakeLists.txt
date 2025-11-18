cmake_minimum_required(VERSION 3.10)
project(FirstGame)

find_package(SDL3 REQUIRED)

add_executable(main
    src/main.cpp
    src/core/Game.cpp
)

target_include_directories(main PRIVATE src)
target_link_libraries(main PRIVATE SDL3::SDL3)