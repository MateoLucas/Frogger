/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "cars.h"

#include <stdlib.h>


CAR* car_init(unsigned int level) {
    CAR* cars;
    int j = 0;
    //Al pasar al nivel 5 se empiezan a repetir los niveles establecidos
    //de manera ciclica pero aumentando la velocidadS
    if (level>LEVEL_5) {
        while(level>5) {
            level -=5;
            j++;
        }
    }
    switch (level) {
    case LEVEL_1:
        cars = (CAR*)malloc(LEVEL_1_CARS1*(sizeof(CAR)));
        for (int i = 0; i<LEVEL_1_CARS1; i++) {
            if (i<LEVEL_1_CARS_11) {
                cars[i].pos.lane = 13;
                cars[i].pos.x = i*BUFFER_W/3;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_1_CARS_11+LEVEL_1_CARS_21) {
                cars[i].pos.lane = 12;
                cars[i].pos.x = (i-LEVEL_1_CARS_11)*BUFFER_W/3;
                cars[i].speed = MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_1_CARS_11+LEVEL_1_CARS_21+LEVEL_1_CARS_31) {
                cars[i].pos.lane = 11;
                cars[i].pos.x = (i-(LEVEL_1_CARS_11+LEVEL_1_CARS_21))*BUFFER_W/3;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_1_CARS_11+LEVEL_1_CARS_21+LEVEL_1_CARS_31+LEVEL_1_CARS_41) {
                cars[i].pos.lane = 10;
                cars[i].pos.x = 0;
                cars[i].speed = FAST_CAR;
                cars[i].length = CARFASTSIZE;
            }
            else if (i<LEVEL_1_CARS_11+LEVEL_1_CARS_21+LEVEL_1_CARS_31+LEVEL_1_CARS_41+LEVEL_1_CARS_51) {
                cars[i].pos.lane = 9;
                cars[i].pos.x = (i-(LEVEL_1_CARS_11+LEVEL_1_CARS_21+LEVEL_1_CARS_31+LEVEL_1_CARS_41))*BUFFER_W/3;
                cars[i].speed = -SLOW_CAR;
                cars[i].length = CARSLOWSIZE;
                
            }
            cars[i].speed *= (1+j/3);
        }
        break;
    case LEVEL_2:
        cars = (CAR*)malloc(LEVEL_2_CARS*(sizeof(CAR)));
        for (int i = 0; i<LEVEL_2_CARS; i++) {
            if (i<LEVEL_2_CARS_1) {
                cars[i].pos.lane = 13;
                cars[i].pos.x = i*BUFFER_W/4;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_2_CARS_1+LEVEL_2_CARS_2) {
                cars[i].pos.lane = 12;
                cars[i].pos.x = (i-LEVEL_2_CARS_1)*BUFFER_W/4;
                cars[i].speed = MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3) {
                cars[i].pos.lane = 11;
                cars[i].pos.x = (i-(LEVEL_2_CARS_1+LEVEL_2_CARS_2))*BUFFER_W/4;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3+LEVEL_2_CARS_4) {
                cars[i].pos.lane = 10;
                cars[i].pos.x = (i-(LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3))*BUFFER_W/5;
                cars[i].speed = FAST_CAR;
                cars[i].length = CARFASTSIZE;
            }
            else if (i<LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3+LEVEL_2_CARS_4+LEVEL_2_CARS_5) {
                cars[i].pos.lane = 9;
                cars[i].pos.x = (i-(LEVEL_2_CARS_1+LEVEL_2_CARS_2+LEVEL_2_CARS_3+LEVEL_2_CARS_4))*BUFFER_W/3;
                cars[i].speed = -SLOW_CAR;
                cars[i].length = CARSLOWSIZE;
                
            }
            cars[i].speed *= (1+j/3);
        }
        break;
    case LEVEL_3:
        cars = (CAR*)malloc(LEVEL_3_CARS*(sizeof(CAR)));
        for (int i = 0; i<LEVEL_3_CARS; i++) {
            if (i<LEVEL_3_CARS_1) {
                cars[i].pos.lane = 13;
                cars[i].pos.x = i*BUFFER_W/4;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_3_CARS_1+LEVEL_3_CARS_2) {
                cars[i].pos.lane = 12;
                cars[i].pos.x = (i-LEVEL_3_CARS_1)*BUFFER_W/4;
                cars[i].speed = MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3) {
                cars[i].pos.lane = 11;
                cars[i].pos.x = (i-(LEVEL_3_CARS_1+LEVEL_3_CARS_2))*BUFFER_W/5;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3+LEVEL_3_CARS_4) {
                cars[i].pos.lane = 10;
                cars[i].pos.x = (i-(LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3))*BUFFER_W/5;
                cars[i].speed = FAST_CAR;
                cars[i].length = CARFASTSIZE;
            }
            else if (i<LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3+LEVEL_3_CARS_4+LEVEL_3_CARS_5) {
                cars[i].pos.lane = 9;
                cars[i].pos.x = (i-(LEVEL_3_CARS_1+LEVEL_3_CARS_2+LEVEL_3_CARS_3+LEVEL_3_CARS_4))*BUFFER_W/3;
                cars[i].speed = -SLOW_CAR;
                cars[i].length = CARSLOWSIZE;
                
            }        
            cars[i].speed *= (1+j/3);
        }
        break;
    case LEVEL_4:
        cars = (CAR*)malloc(LEVEL_4_CARS*(sizeof(CAR)));
        for (int i = 0; i<LEVEL_4_CARS; i++) {
            if (i<LEVEL_4_CARS_1) {
                cars[i].pos.lane = 13;
                cars[i].pos.x = i*BUFFER_W/4;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_4_CARS_1+LEVEL_4_CARS_2) {
                cars[i].pos.lane = 12;
                cars[i].pos.x = (i-LEVEL_4_CARS_1)*BUFFER_W/4;
                cars[i].speed = MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3) {
                cars[i].pos.lane = 11;
                cars[i].pos.x = (i-(LEVEL_4_CARS_1+LEVEL_4_CARS_2))*BUFFER_W/4;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3+LEVEL_4_CARS_4) {
                cars[i].pos.lane = 10;
                cars[i].pos.x = (i-(LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3))*BUFFER_W/5;
                cars[i].speed = FAST_CAR;
                cars[i].length = CARFASTSIZE;
            }
            else if (i<LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3+LEVEL_4_CARS_4+LEVEL_4_CARS_5) {
                cars[i].pos.lane = 9;
                cars[i].pos.x = (i-(LEVEL_4_CARS_1+LEVEL_4_CARS_2+LEVEL_4_CARS_3+LEVEL_4_CARS_4))*BUFFER_W/3;
                cars[i].speed = -SLOW_CAR;
                cars[i].length = CARSLOWSIZE;
                
            }        
            cars[i].speed *= (1+j/3);
        }
        break;
        case LEVEL_5:
        cars = (CAR*)malloc(LEVEL_5_CARS*(sizeof(CAR)));
        for (int i = 0; i<LEVEL_5_CARS; i++) {
            if (i<LEVEL_5_CARS_1) {
                cars[i].pos.lane = 13;
                cars[i].pos.x = i*BUFFER_W/5;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_5_CARS_1+LEVEL_5_CARS_2) {
                cars[i].pos.lane = 12;
                cars[i].pos.x = (i-LEVEL_5_CARS_1)*BUFFER_W/4;
                cars[i].speed = MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3) {
                cars[i].pos.lane = 11;
                cars[i].pos.x = (i-(LEVEL_5_CARS_1+LEVEL_5_CARS_2))*BUFFER_W/5;
                cars[i].speed = -MEDIUM_CAR;
                cars[i].length = CARMEDIUMSIZE;
            }
            else if (i<LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3+LEVEL_5_CARS_4) {
                cars[i].pos.lane = 10;
                cars[i].pos.x = (i-(LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3))*BUFFER_W/5;
                cars[i].speed = FAST_CAR;
                cars[i].length = CARFASTSIZE;
            }
            else if (i<LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3+LEVEL_5_CARS_4+LEVEL_5_CARS_5) {
                cars[i].pos.lane = 9;
                cars[i].pos.x = (i-(LEVEL_5_CARS_1+LEVEL_5_CARS_2+LEVEL_5_CARS_3+LEVEL_5_CARS_4))*BUFFER_W/3;
                cars[i].speed = -SLOW_CAR;
                cars[i].length = CARSLOWSIZE;
                
            }        
            cars[i].speed *= (1+j/3);
        }
        break;
    }
    return cars;
}
    
void car_update(CAR* cars, unsigned int amount) {
    int size;
    //Mueve los autos
    for (int i = 0; i < amount; i++) {
        size = cars[i].length;
        cars[i].pos.x += cars[i].speed;
        if (cars[i].pos.x > BUFFER_W+1) {
            if (cars[i].speed > 0) {
                cars[i].pos.x = -size;
            }
        }
        //si sale de la pantalla lo vuelve a poner por el otro lado
        else if (cars[i].pos.x < -size) {
            if (cars[i].speed < 0) {
                cars[i].pos.x = BUFFER_W;
            }
        }
    }
    return;
}
