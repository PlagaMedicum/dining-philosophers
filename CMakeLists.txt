project(dining_philosophers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # ycm things.

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(MAIN main.cpp src/dining_philosophers.cpp src/philosopher.cpp src/stick.cpp)
add_executable(main ${MAIN})
