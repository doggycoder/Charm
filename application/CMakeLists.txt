cmake_minimum_required(VERSION 3.13)
project(QtFaceResearch)

add_definitions(-std=c++11)
add_subdirectory(../qt qt.out)
include_directories(../)
include_directories(../engine)

aux_source_directory(test TEST_SHAPRE)

find_package(Qt5 REQUIRED Widgets Core)
aux_source_directory(. SRC_SOURCE)

set(SOURCE_LIST ${SRC_SOURCE})

add_executable(${PROJECT_NAME} ${SOURCE_LIST} ${TEST_SHAPRE})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core CharmEngine QTTool)
