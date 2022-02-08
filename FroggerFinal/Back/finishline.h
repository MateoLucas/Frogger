 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   finishline.h
 * Author: mariano
 *
 * Created on October 20, 2021, 11:49 AM
 */

#ifndef FINISHLINE_H
#define FINISHLINE_H

#include <stdbool.h>
#include <stdlib.h>
#include "timer.h"
#include "frog.h"

#ifdef RASPI
#define BASE_NUM 5
#define CORRECCION 1
#define BASE_S 2//90
#define BASE_D 1//125
#define FRAME_COUNT 100
#else
#define BASE_NUM 5
#define CORRECCION 3
#define BASE_S BUFFER_W/9//90
#define BASE_D BUFFER_W/9//125
#define FRAME_COUNT 500
#endif



typedef struct{
    bool used;
    bool obj;
}BASE;

//Inicializa las bases donde puede aterrizar 
BASE* base_init(void);

//Maneja la linea de llegada con las bases, la rana, la mosca y el cocodrilo
bool finishline(BASE* bases, TIME* timer, FROG* frog, int level);


#endif /* FINISHLINE_H */

