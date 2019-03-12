cmake_minimum_required(VERSION 3.13)
project(QTTool)

find_package(Qt5 REQUIRED Widgets Core)

add_definitions(-std=c++11)
add_definitions(-pthread)
include(glwidget/CMakeLists.txt)
include_directories(.)
set(SRC_QT_TOOL_LIST ${SRC_GL_WIDGET})
add_library(${PROJECT_NAME} STATIC ${SRC_QT_TOOL_LIST})
add_dependencies(${PROJECT_NAME} Qt5::Widgets Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core GL pthread)
