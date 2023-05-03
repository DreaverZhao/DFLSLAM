cmake_minimum_required( VERSION 3.0 )
project( train_voc )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++17 -O3" )

# opencv 
find_package( OpenCV 3.1 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set( FBOW_INCLUDE_DIRS "/usr/local/include" )
set( FBOW_LIBS "/usr/local/lib/libfbow.so" )

add_executable( feature_training feature_training.cpp )
target_link_libraries( feature_training ${OpenCV_LIBS} ${FBOW_LIBS} )
