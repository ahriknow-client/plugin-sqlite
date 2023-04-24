cmake_minimum_required(VERSION 3.14)

project(sqliteplugin VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/plugin/module/inc)

qt5_add_resources(PROJECT_SOURCES sqliteplugin.qrc)

add_subdirectory(plugin)
find_library(MODULE module PATHS ${CMAKE_SOURCE_DIR}/plugin/module/lib)

add_library(sqliteplugin SHARED
    plugin/inc/ipluginmodule.h

    plugin/module/inc/activitybutton.h
    plugin/module/inc/sidewidget.h
    plugin/module/inc/editwidget.h

    inc/sqliteplugin.h
    src/sqliteplugin.cpp
)

target_link_libraries(sqliteplugin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${MODULE})

target_compile_definitions(sqliteplugin PRIVATE PLUGIN_LIBRARY)
