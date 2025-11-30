cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

project(LR7)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG
    "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address,leak,undefined")

include_directories(include)

set(SOURCES
    src/run_tasks.cpp
    src/task_1.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
