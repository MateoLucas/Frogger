/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "rasp_input.h"



void init_input() {
    joy_init();
}

int menu(bool playing, bool first_time, int* index) {
    jcoord_t joy_input;
    jswitch_t joy_s;
    static int delay = 0;
    int ret;
    joy_update();
    joy_input = joy_get_coord();
    joy_s = joy_get_switch();
    delay++;
    if(joy_input.y>10)
    {
        if( *index > NEW_GAME)
        {
            if(delay >= MENU_DELAY) 
            {
                (*index)--;
                delay = 0;
                //moment = true;
            }
        }
    }
    else if(joy_input.y<-10)
    {
        if(*index < QUIT_GAME)
            if(delay >= MENU_DELAY)
            {
                (*index)++;
                delay = 0;
            }
    }
    if (joy_s == J_PRESS && delay > MENU_DELAY)
    {
        ret = *index;
        delay=0;
    }
    else
        ret = CONTINUE_MENU;
    
    return ret;
}


int game(int* key_pressed, bool* redraw) {
    jcoord_t joy_input;
    jswitch_t joy_s;
    static int delay = 0;
    delay++;
    joy_update();
    joy_s = joy_get_switch();
    joy_input = joy_get_coord();
    int ret = NO_KEY_PRESSED;
    if(joy_s==J_PRESS && delay >= MENU_DELAY) {    
        *key_pressed = PAUSE;
        ret = KEY_PRESSED;
        delay=0;
    }
    else if(joy_input.x < -JOY_THREASHOLD && abs(joy_input.y) < abs(joy_input.x)) {
        *key_pressed = LEFT;
        ret = KEY_PRESSED;
        delay=0;
    }
    else if(joy_input.x > JOY_THREASHOLD && abs(joy_input.y) < abs(joy_input.x)) {
        *key_pressed = RIGHT;
        ret = KEY_PRESSED;
        delay=0;
    }
    else if(joy_input.y > -JOY_THREASHOLD && abs(joy_input.x) < abs(joy_input.y) ) {
        *key_pressed = UP;
        ret = KEY_PRESSED;
        delay=0;
    }
    else if(joy_input.y < JOY_THREASHOLD && abs(joy_input.x) < abs(joy_input.y)) {
        *key_pressed = DOWN;
        ret = KEY_PRESSED;
        
    }
    else
        *key_pressed = NONE;
    *redraw = true;
    return ret;
}

bool redraw_func(bool redraw) {
    return redraw;
}