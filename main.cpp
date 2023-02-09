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
#include <unistd.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lvgl/demos/lv_demos.h"
#define LCD_WIDTH   320
#define LCD_HEIGHT  240
void lvgl_disp_init();



int main(int argc, char const *argv[])
{
    /* Lvgl init */
    lv_init();
    lvgl_disp_init();

    printf("lvgl frame buffer test :)\n");

    



    // lv_demo_widgets();
    // lv_demo_stress();
    lv_demo_benchmark();
    // lv_demo_music();



    while(1)
    {
        /* Periodically call the lv_task handler.
        * It could be done in a timer interrupt or an OS task too.*/
        lv_timer_handler();
        usleep(5 * 1000);
    }





    




    return 0;
}



void lvgl_disp_init()
{
    /* Try ping pong buffer */
    /* Linux frame buffer device init */
    fbdev_init();
    
    /* A small buffer for LittlevGL to draw the screen's content */
    static lv_color_t buf_1[LCD_WIDTH * LCD_HEIGHT];
    static lv_color_t buf_2[LCD_WIDTH * LCD_HEIGHT];

    /* Initialize a descriptor for the buffer */
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, LCD_WIDTH * LCD_HEIGHT);

    /* Initialize and register a display driver */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = LCD_HEIGHT;
    disp_drv.ver_res    = LCD_WIDTH;
    lv_disp_drv_register(&disp_drv);
}
