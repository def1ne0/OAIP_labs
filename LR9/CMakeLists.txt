cmake_minimum_required(VERSION 4.1)
project(LR9)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LR9
        main.cpp
        src/MainWindow.cpp
        src/MainWindow.h
        src/MovingRectangle.cpp
        src/MovingRectangle.h
)

target_link_libraries(LR9
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

