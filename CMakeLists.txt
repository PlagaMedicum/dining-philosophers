cmake_minimum_required(VERSION 3.10)

project(dining_philosophers)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # ycm things.

find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SRC_FILES main.cpp src/dining_philosophers.cpp src/dining_philosophers.h src/philosopher.cpp src/philosopher.h src/stick.cpp src/stick.h)
add_executable(dine ${SRC_FILES})
target_link_libraries (dine ${CMAKE_THREAD_LIBS_INIT})
