# submodule
add_subdirectory(lv_drivers)
add_subdirectory(tslib)

add_library(lvgl_porting
    lv_port_disp.c
    lv_port_disp.h
    lv_port_indev.c
    lv_port_indev.h
)
target_link_libraries(lvgl_porting lvgl_drivers tslib)
