/**
 * @file main.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <unistd.h>

#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_porting/lv_port_disp.h"
#include "lv_porting/lv_port_indev.h"




int main(int argc, char const *argv[])
{
    /* Lvgl init */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    printf("lvgl template with framebuffer :)\n");



    lv_demo_widgets();
    // lv_demo_stress();
    // lv_demo_benchmark();
    // lv_demo_music();





    while(1)
    {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}


