cmake_minimum_required(VERSION 3.28)
project(qt_cmake_boilerplate LANGUAGES CXX VERSION 0.1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(
    Qt6
    COMPONENTS Core Gui Widgets Svg LinguistTools
    CONFIG
    REQUIRED
)

# add_subdirectory(controls)
add_subdirectory(app bin)
