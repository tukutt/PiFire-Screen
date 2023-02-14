// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void clock_pull_down_Animation(lv_obj_t * TargetObject, int delay);
void logo_popout_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Clock;
extern lv_obj_t * ui_PanelBG;
extern lv_obj_t * ui_LogoPanel;
extern lv_obj_t * ui_LogoC;
extern lv_obj_t * ui_LogoM;
extern lv_obj_t * ui_Logo4;
extern lv_obj_t * ui_ClockPanel;
extern lv_obj_t * ui_TimeHour;
extern lv_obj_t * ui_TimeMinute;
extern lv_obj_t * ui_ImageWeather;


LV_IMG_DECLARE(ui_img_logobg_png);    // assets\LogoBG.png
LV_IMG_DECLARE(ui_img_clockbg_png);    // assets\ClockBG.png
LV_IMG_DECLARE(ui_img_sunny_png);    // assets\Sunny.png


LV_FONT_DECLARE(ui_font_HarmonyOSSansSCLight);
LV_FONT_DECLARE(ui_font_HarmonyOSSansSCMedium);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
