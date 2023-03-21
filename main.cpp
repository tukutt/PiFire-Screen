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
/* Using SDL2 */
#define DISP_USING_SDL      0
/* Using framebuffer directly, config your fb in lv_drv_conf.h */
#define DISP_USING_FB       1
/* Enable touch pad */
#define USING_TOUCH_PAD     1
/* Use offical demos */
#define USING_LVGL_DEMOS    1


#include <iostream>
#include <string>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_porting/lv_port_disp.h"
#include "lv_porting/lv_port_indev.h"
#include "ui.h"
#include "time.h"
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>


static char* get_IP_address();
static char* get_host_name();
static double get_cpu_load();
static double get_memory_usage();
static void data_update(lv_timer_t * timer);


int main(int argc, char const *argv[])
{
    printf("> CM4Stack Lvgl demo <\n> Press ctrl + c to quit\n");

    /* Lvgl init */
    lv_init();

    /* Display init */
    #if DISP_USING_SDL
    lv_port_disp_init(0);
    #endif
    #if DISP_USING_FB
    lv_port_disp_init(1);
    #endif

    /* Input device init */
    lv_port_indev_init(USING_TOUCH_PAD);
    

    /* Lvgl offical demos */
    #if USING_LVGL_DEMOS
        lv_demo_widgets();
        // lv_demo_stress();
        // lv_demo_benchmark();
        // lv_demo_music();
    #else
        /* Little clock demo */
        ui_init();
        lv_timer_t * timer = lv_timer_create(data_update, 1000, NULL);
        data_update(NULL);
        cover_pull_down_Animation(ui_CoverPanel, 0);
        logo_popout_Animation(ui_LogoC, 300 + 0);
        logo_popout_Animation(ui_LogoM, 300 + 100);
        logo_popout_Animation(ui_Logo4, 300 + 200);
        cover_pull_up_Animation(ui_CoverPanel, 3000);
    #endif


    while(1)
    {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}


char* get_IP_address()
{
    int fd;
    struct ifreq ifr;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;
    /* I want IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    /* display result */
    static char ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr), ip_address, INET_ADDRSTRLEN);
    // printf("%s\n", ip_address);
    return ip_address;
}


char* get_host_name()
{
    static char hostname[1024];
    gethostname(hostname, sizeof hostname);
    return hostname;
}


double get_cpu_load()
{
    double load_avg[3];
    getloadavg(load_avg, 3);
    return load_avg[0];
}


double get_memory_usage()
{
    FILE* file = fopen("/proc/meminfo", "r");
    unsigned long mem_total, mem_free;
    fscanf(file, "MemTotal: %lu kB\nMemFree: %lu kB", &mem_total, &mem_free);
    fclose(file);

    double mem_usage = (double)(mem_total - mem_free) / mem_total * 100;
    // printf("%ld %ld %f\n", mem_total, mem_free, mem_usage);
    return mem_usage;
}


void data_update(lv_timer_t * timer)
{
    /* get time */
    time_t result = time(NULL);   
    tm* time_now = localtime(&result);
    // printf("%.2d:%.2d\n", time_now->tm_hour, time_now->tm_min);
    lv_label_set_text_fmt(ui_TimeHour, "%.2d", time_now->tm_hour);
    lv_label_set_text_fmt(ui_TimeMinute, "%.2d", time_now->tm_min);

    /* update sys infos */
    char data_buff[100];
    snprintf(data_buff, sizeof(data_buff), "> hostname: %s\n> ip: %s\n> laod average: %.2f\n> mem usage: %.2f%%",
                get_host_name(),
                get_IP_address(),
                get_cpu_load(),
                get_memory_usage());
    lv_label_set_text(ui_LabelSysInfos, data_buff);
}