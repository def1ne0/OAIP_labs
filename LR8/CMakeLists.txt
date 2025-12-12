cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

project(LR8)

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG
    "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address,leak,undefined")

include_directories(include)

add_executable(airport src/airport.c)
add_executable(railway_station src/railway_station.c)

target_include_directories(airport PRIVATE include)
target_include_directories(railway_station PRIVATE include)

target_sources(airport PRIVATE src/tasks/task_1.c)
target_sources(railway_station PRIVATE src/tasks/task_2.c)

add_custom_target(airport-task
    COMMAND airport
    DEPENDS airport
)

add_custom_target(railway-station-task
    COMMAND station
    DEPENDS railway_station
)
