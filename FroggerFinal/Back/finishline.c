/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "finishline.h"


BASE* base_init(void) {
    BASE* bases;
    bases = (BASE*)malloc(BASE_NUM*(sizeof(BASE)));
    for (int i = 0; i < BASE_NUM; i++) {
        bases[i].used = false;
        bases[i].obj = false;
    }    
    return bases;
}

#define BASE_POINTS 50
#define TIME_POINTS 20
#define FLY_POINTS 200
#define LEVEL_POINTS 1000
//Devuelve falso a menos que haya una rana en todas las bases
//Detecta las ranas en las bases y ubica las moscas y cocodrilos en las bases
bool finishline(BASE* bases, TIME* timer, FROG* frog, int level,bool* new_game) {
    bool ret=false;    
    static bool obj_active = false;
    static int framecount = FRAME_COUNT;
    static int count = 0;
    static int level_change=1;
    if (level!=level_change|| *new_game) {
        *new_game = false;
        level_change=level;
        count=0;
    }
    if (!obj_active){
        if (framecount)
            framecount--;
        else {
            int num = rand()%5;
            if (!bases[num].used){
                bases[num].obj = true;
                obj_active = true;
                framecount = FRAME_COUNT;
            }
        }
    }
    else {
        framecount--;
        if (!framecount) {
            obj_active = false;
            int i;
            for (i=0;i<BASE_NUM;i++) {
                bases[i].obj = false;
            }            
            framecount= FRAME_COUNT;
        }            
    }
    if (frog->pos.lane==2) {
        for (int i = 0;i<BASE_NUM;i++) {
            
            if (frog->pos.x>=(CORRECCION+BASE_S*i+BASE_D*i) && (frog->pos.x<=(CORRECCION+BASE_S*(1+i)+BASE_D*i-FROG_W+1)) && (bases[i].used==false)){                                        
                if (bases[i].obj&&(level%2!=0)) {
                    frog->score += FLY_POINTS;
                    obj_active = false;
                    bases[i].obj = false;
                    framecount = FRAME_COUNT;
                    bases[i].used=true;
                    count++;
                    frog->score += BASE_POINTS + TIME_POINTS*timer->countdown;
                }
                else if (bases[i].obj&&(level%2==0)) {
                    frog->lives-=1;
                }
                else {
                    bases[i].used=true;
                    count++;
                    frog->score += BASE_POINTS  + TIME_POINTS*timer->countdown;
                }
                if (count==BASE_NUM) {
                    frog->score+=LEVEL_POINTS;
                    ret=true;
                }                    
                *timer = timer_init();
                frog->pos.lane = LANES_N;
                frog->lowest_lane = LANES_N;
            }
           
        }
    }
    return ret;
}



