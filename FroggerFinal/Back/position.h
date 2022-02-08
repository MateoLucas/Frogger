#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>
#define MIDDLE_LANE 8
#define FINAL_LANE 15
#define FIRST_LANE 0
#define LANES_N 14

#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3
#define LEVEL_4 4
#define LEVEL_5 5



#ifdef RASPI
#define BUFFER_W FINAL_LANE 
#define LANE_W 1
#define BUFFER_H FINAL_LANE  
#define DISPLAY_W FINAL_LANE
#define DISPLAY_H FINAL_LANE
#else
#define LANE_W 71
#define BUFFER_W (LANE_W*(LANES_N))
#define BUFFER_H 1000    
#define DISPLAY_W 500
#define DISPLAY_H 500

#endif

typedef struct {
    float x;
    unsigned int lane;
} POS;
//Tipo de dato que usa el juego para expresar posiciones

//Detecta si dos elementos colisionan
bool collision(POS pos1, int size1, POS pos2, int size2);

#endif 