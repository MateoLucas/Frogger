    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cars.h
 * Author: mateo
 *
 * Created on August 3, 2021, 10:50 AM
 */

#ifndef CARS_H
#define CARS_H
#include <stdbool.h>
#include "position.h"


#define LEVEL_1_CARS_11 3
#define LEVEL_1_CARS_21 3
#define LEVEL_1_CARS_31 3
#define LEVEL_1_CARS_41 1
#define LEVEL_1_CARS_51 2
#define LEVEL_1_CARS1 (LEVEL_1_CARS_11+LEVEL_1_CARS_21+LEVEL_1_CARS_31+LEVEL_1_CARS_41+LEVEL_1_CARS_51)

#define LEVEL_2_CARS_1 4
#define LEVEL_2_CARS_2 4
#define LEVEL_2_CARS_3 4
#define LEVEL_2_CARS_4 2
#define LEVEL_2_CARS_5 3
#define LEVEL_2_CARS (LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3+LEVEL_2_CARS_4+LEVEL_2_CARS_5)

#define LEVEL_3_CARS_1 4
#define LEVEL_3_CARS_2 4
#define LEVEL_3_CARS_3 5
#define LEVEL_3_CARS_4 2
#define LEVEL_3_CARS_5 3
#define LEVEL_3_CARS (LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3+LEVEL_3_CARS_4+LEVEL_3_CARS_5)

#define LEVEL_4_CARS_1 4
#define LEVEL_4_CARS_2 4
#define LEVEL_4_CARS_3 4
#define LEVEL_4_CARS_4 3
#define LEVEL_4_CARS_5 4
#define LEVEL_4_CARS (LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3+LEVEL_4_CARS_4+LEVEL_4_CARS_5)

#define LEVEL_5_CARS_1 5
#define LEVEL_5_CARS_2 4
#define LEVEL_5_CARS_3 5
#define LEVEL_5_CARS_4 4
#define LEVEL_5_CARS_5 3
#define LEVEL_5_CARS (LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3+LEVEL_5_CARS_4+LEVEL_5_CARS_5)

#ifdef RASPI
#define CARSLOWSIZE 3
#define CARMEDIUMSIZE 1
#define CARFASTSIZE 1
#define SLOW_CAR 0.025//0.0000000
#define MEDIUM_CAR 0.05//0.000000
#define FAST_CAR 0.15//0.0000000
#else
#define CARSLOWSIZE 117
#define CARMEDIUMSIZE 87
#define CARFASTSIZE 88
#define SLOW_CAR 1
#define MEDIUM_CAR 2
#define FAST_CAR 7
#endif

typedef struct
{
    POS pos;
    float speed;
    int length;
} CAR;

//Inicializa los autos para cada nivel
CAR* car_init(unsigned int level);

//Actualiza la posición de todos los autos
void car_update(CAR* cars, unsigned int amount);

#endif /* CARS_H */



