/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   frog.h
 * Author: mateo
 *
 * Created on August 3, 2021, 10:58 AM
 */

#ifndef FROG_H
#define FROG_H
#include <stdlib.h>
#include "cars.h"
#include "logs.h"

//Jumping frames es la cantidad de frames que dura un salto
//que sea par SI O SI
#define JUMPING_FRAMES 10
//que sea par SI O SI

//Macros para definir direcciones
#define FRONT_DIR 1
#define LEFT_DIR 2
#define RIGHT_DIR 3
#define BACK_DIR 4

#define LIVES 3
#ifndef RASPI
#define FROG_L  20//length
#define FROG_W  53//width
#define FROG_J_V  LANE_W//frog jump leng
#define FROG_J_H LANE_W/2
#else
#define FROG_L 1
#define FROG_W 1    
#define FROG_J_V    1
#define FROG_J_H    1
#endif


typedef struct
{
    POS pos;
    int jumping;   //esta en el aire saltando. 0 es que no, sube el valor con los frames
    int direc;  //direcction its facing
    int lives;
    int score;
    int lowest_lane;
}FROG;

//Iicializa la rana
FROG* frog_init(int lives, int score);

//Actualiza la rana, la mueve y detecta colisiones
void frog_update(TURTLES* turtles,FROG* frog, LOG* log, CAR* car,SNEK* sneks, int snekamount,int carsamount, int logsamount, int turtlesamount);//, FLY* fly); // faltan consts



#endif /* FROG_H */

