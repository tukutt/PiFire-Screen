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

# app
file(GLOB APP_SRCS
    app/ui/*.c
)
include_directories(app/ui)

add_executable(PiFire-Screen main.cpp ${APP_SRCS})
target_link_libraries(PiFire-Screen
    lvgl
    lvgl_porting
    tick
)
