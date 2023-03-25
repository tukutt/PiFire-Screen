cmake_minimum_required(VERSION 3.0.0)
project(PiFire-Screen VERSION 0.1.0)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# tick
add_library(tick tick.c)


# lvgl
add_subdirectory(lvgl)
add_subdirectory(lv_porting)


add_executable(PiFire-Screen main.cpp)
target_link_libraries(PiFire-Screen
    lvgl
    lvgl_porting
    lvgl_examples
    lvgl_demos
    tick
)
