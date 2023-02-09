cmake_minimum_required(VERSION 3.0.0)
project(play VERSION 0.1.0)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# tick
add_library(tick tick.c)

# lvgl
add_subdirectory(lvgl)
add_subdirectory(lv_porting)


add_executable(play main.cpp)
target_link_libraries(play
    lvgl
    lvgl_porting
    lvgl_examples
    lvgl_demos
    tick
)



add_custom_command(TARGET play
    POST_BUILD
    COMMAND /home/parker/projects/CM4/LvglTemplate_CM4/copy.sh
)