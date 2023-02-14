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

#include "ui.h"
#include "time.h"





void clock_update(lv_timer_t * timer)
{
    time_t result = time(NULL);   
    tm* time_now = localtime(&result);
    // printf("%.2d:%.2d\n", time_now->tm_hour, time_now->tm_min);
    lv_label_set_text_fmt(ui_TimeHour, "%.2d", time_now->tm_hour);
    lv_label_set_text_fmt(ui_TimeMinute, "%.2d", time_now->tm_min);
}






int main(int argc, char const *argv[])
{
    /* Lvgl init */
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    printf("lvgl template with framebuffer :)\n");
    printf("ctrl + c to quit\n");



    // lv_demo_widgets();
    // lv_demo_stress();
    // lv_demo_benchmark();
    // lv_demo_music();



    ui_init();
    lv_timer_t * timer = lv_timer_create(clock_update, 1000, NULL);

    clock_update(NULL);
    clock_pull_down_Animation(ui_ClockPanel, 3000);
    logo_popout_Animation(ui_LogoC, 0);
    logo_popout_Animation(ui_LogoM, 100);
    logo_popout_Animation(ui_Logo4, 200);






    while(1)
    {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}
