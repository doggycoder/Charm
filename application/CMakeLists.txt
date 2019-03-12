cmake_minimum_required(VERSION 3.13)
project(QtFaceResearch)

add_definitions(-std=c++11)
add_subdirectory(../qt qt.out)
include_directories(../)
include_directories(../engine)

link_directories(../thirdparty/opencv-3.4.5)
find_package(OpenCV QUIET COMPONENTS core highgui imgproc imgcodecs videoio)

aux_source_directory(camera SRC_CAMERA)
aux_source_directory(test TEST_SHAPRE)

find_package(Qt5 REQUIRED Widgets Core)
aux_source_directory(. SRC_SOURCE)

set(SOURCE_LIST ${SRC_SOURCE})

add_executable(${PROJECT_NAME} ${SOURCE_LIST} ${TEST_SHAPRE} ${SRC_CAMERA})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core CharmEngine QTTool opencv_calib3d opencv_features2d opencv_flann opencv_imgproc opencv_core dl z)
