cmake_minimum_required(VERSION 3.8)
project(GestureReconstruction)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp gesture_db.cpp gesture_db.h gesture_acts.cpp gesture_acts.h)
add_executable(GestureReconstruction ${SOURCE_FILES})

target_link_libraries(GestureReconstruction sqlite3)