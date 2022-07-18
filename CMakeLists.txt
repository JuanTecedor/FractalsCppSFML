cmake_minimum_required(VERSION 3.22.1)

project("FractalsCppSFML" VERSION 0.0.1)

set(EXECUTABLE_NAME "fractals")
set(EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML REQUIRED COMPONENTS graphics window system)
include_directories(${PROJECT_NAME} ${SFML_INCLUDE_DIRS})

set(SOURCES)
set(SOURCES ${SOURCES}
    src/fractals/fractal.cpp
    src/fractals/sierpinski.cpp
    src/fractals/sierpinskiTriangle.cpp
)
set(SOURCES ${SOURCES} src/main.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_compile_options(${EXECUTABLE_NAME} PRIVATE -g -Wall -Wextra -Wpedantic -Werror=format-security -Werror=implicit-function-declaration)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} -lsfml-graphics -lsfml-window -lsfml-system)
