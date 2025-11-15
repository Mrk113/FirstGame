cmake_minimum_required(VERSION 3.5)
project(FirstGame)

find_package(SDL3 REQUIRED)

add_executable(main src/main.cpp src/Game.cpp)

target_link_libraries(main PRIVATE SDL3::SDL3)
