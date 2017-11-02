cmake_minimum_required(VERSION 3.8)
project(GestureReconstruction)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/gesture_db.cpp src/gesture_db.h src/gesture_acts.cpp src/gesture_acts.h src/gesture_reconstruct.cpp src/gesture_reconstruct.h)
add_executable(GestureReconstruction ${SOURCE_FILES})

target_link_libraries(GestureReconstruction sqlite3)