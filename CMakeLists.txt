cmake_minimum_required(VERSION 3.17)

project(FaceDetector LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp src/FaceDetector.cpp src/BlurDrawer.cpp include/BlurDrawer.h)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# OpenCV setup
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

find_package( Boost REQUIRED COMPONENTS program_options regex )
include_directories( ${Boost_INCLUDE_DIRS} )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

target_link_libraries(${PROJECT_NAME}  rt)

# Introduce preprocessor variables to keep paths of asset files
set(FACE_DETECTION_CONFIGURATION
        "${PROJECT_SOURCE_DIR}/assets/deploy.prototxt")

set(FACE_DETECTION_WEIGHTS
        "${PROJECT_SOURCE_DIR}/assets/res10_300x300_ssd_iter_140000_fp16.caffemodel")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        FACE_DETECTION_CONFIGURATION="${FACE_DETECTION_CONFIGURATION}")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        FACE_DETECTION_WEIGHTS="${FACE_DETECTION_WEIGHTS}")