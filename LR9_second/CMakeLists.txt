cmake_minimum_required(VERSION 4.1)
project(LR9_second)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LR9_second main.cpp
        src/Shape.cpp
        src/Shape.h
        src/Polygon.cpp
        src/Polygon.h
        src/Triangle.cpp
        src/Triangle.h
        src/Rectangle.cpp
        src/Rectangle.h
        src/Square.cpp
        src/Square.h
        src/Rhombus.cpp
        src/Rhombus.h
        src/Star.cpp
        src/Star.h
        src/Hexagon.cpp
        src/Hexagon.h
        src/Circle.cpp
        src/Circle.h
        src/MainWindow.cpp
        src/MainWindow.h
        src/GraphicsView.cpp
        src/GraphicsView.h)
target_link_libraries(LR9_second
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

