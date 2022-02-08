/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "timer.h"

TIME timer_init(void)
{
    TIME timer;
    timer.base_time = time(NULL);//al_get_time();
    timer.max_time = MAX_TIME;
    timer.countdown = timer.max_time;
    return timer;
}

double get_countdown(TIME timer)
{
    time_t tiempo = time(NULL);//al_get_time();
    time_t ret = timer.max_time;
    ret -= tiempo-timer.base_time;
    return ret;
}

