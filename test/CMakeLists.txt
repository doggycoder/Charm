cmake_minimum_required(VERSION 3.13)
project(ProjectTest)

add_definitions(-std=c++11)
aux_source_directory(shape TEST_SHAPRE)
include_directories(../engine)
include_directories(.)

set(SRC_TEST ${TEST_SHAPRE})
add_library(ProjectTest STATIC ${SRC_TEST})
target_link_libraries(ProjectTest CharmEngine)
