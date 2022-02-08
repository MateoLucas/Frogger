

/* 
 * File:   logs.h
 * Author: mateo
 *
 * Created on August 3, 2021, 10:50 AM
 */

#ifndef LOGS_H
#define LOGS_H
#include "position.h"
#include <stdbool.h>


#define LEVEL_1_DIVING_TURTLES 2
#define LEVEL_1_SHORT_LOGS 3
#define LEVEL_1_MEDIUM_LOGS 3
#define LEVEL_1_LONG_LOGS 2
#define LEVEL_1_LONG_TURTLES 3
#define LEVEL_1_SHORT_TURTLES 3
#define LEVEL_1_SNEKS 0
#define LEVEL_1_LOGS (LEVEL_1_SHORT_LOGS+LEVEL_1_MEDIUM_LOGS+LEVEL_1_LONG_LOGS+LEVEL_1_LONG_TURTLES+LEVEL_1_SHORT_TURTLES)

#define LEVEL_2_DIVING_TURTLES 3
#define LEVEL_2_SHORT_LOGS 3
#define LEVEL_2_MEDIUM_LOGS 2
#define LEVEL_2_LONG_LOGS 1
#define LEVEL_2_LONG_TURTLES 2
#define LEVEL_2_SHORT_TURTLES 4
#define LEVEL_2_SNEKS 0
#define LEVEL_2_LOGS (LEVEL_2_SHORT_LOGS+LEVEL_2_MEDIUM_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_LONG_TURTLES+LEVEL_2_SHORT_TURTLES)

#define LEVEL_3_DIVING_TURTLES 3
#define LEVEL_3_SHORT_LOGS 3
#define LEVEL_3_MEDIUM_LOGS 1
#define LEVEL_3_LONG_LOGS 1
#define LEVEL_3_LONG_TURTLES 2
#define LEVEL_3_SHORT_TURTLES 3
#define LEVEL_3_DUCK 1
#define LEVEL_3_SNEKS 1
#define LEVEL_3_LOGS (LEVEL_3_DUCK+LEVEL_3_SHORT_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES)

#define LEVEL_4_DIVING_TURTLES 3
#define LEVEL_4_SHORT_LOGS 2
#define LEVEL_4_MEDIUM_LOGS 1
#define LEVEL_4_LONG_LOGS 1
#define LEVEL_4_LONG_TURTLES 2
#define LEVEL_4_SHORT_TURTLES 2
#define LEVEL_4_DUCK 1
#define LEVEL_4_SNEKS 1
#define LEVEL_4_LOGS (LEVEL_4_DUCK+LEVEL_4_SHORT_LOGS+LEVEL_4_MEDIUM_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_LONG_TURTLES+LEVEL_4_SHORT_TURTLES)

#define LEVEL_5_DIVING_TURTLES 3
#define LEVEL_5_SHORT_LOGS 2
#define LEVEL_5_MEDIUM_LOGS 0
#define LEVEL_5_LONG_LOGS 1
#define LEVEL_5_LONG_TURTLES 1
#define LEVEL_5_SHORT_TURTLES 2
#define LEVEL_5_DUCK 1
#define LEVEL_5_SNEKS 1
#define LEVEL_5_LOGS (LEVEL_5_DUCK+LEVEL_5_SHORT_LOGS+LEVEL_5_MEDIUM_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_LONG_TURTLES+LEVEL_5_SHORT_TURTLES)

#ifdef RASPI
#define LONG_LOG_IMAGE_SIZE 2.5
#define MEDIUM_LOG_L 3
#define SHORT_LOG_L 2
#define SNEK_L 3//70
#define SNEKSPD 0
#define TRTLSHORT_L 2
#define TRTLLONG_L 3
#define CROC_L 2
#define CROC_L_OPEN 3
#define LOGSPD_S 0.025
#define LOGSPD_F 0.075
#define TRTLSPD_S -0.05
#define TRTLSPD_F -0.1
#define DIVE_TIMER 40
#define DUCK_L 1
#define DUCKSPD 0.4
#else
#define SHORT_LOG_L 123
#define MEDIUM_LOG_L 185
#define LONG_LOG_IMAGE_SIZE 233
#define SNEK_L 105//70
#define SNEKSPD 3
#define TRTLSHORT_L 95
#define TRTLLONG_L 145
#define CROC_L 184
#define CROC_L_OPEN 140
#define LOGSPD_S 2
#define LOGSPD_F 4
#define TRTLSPD_S -3
#define TRTLSPD_F -5
#define SLOW_SPEED 3
#define MEDIUM_SPEED 5
#define FAST_SPEED 7
#define DIVE_TIMER 100
#define DUCK_L 50
#define DUCKSPD 5
#endif

#define TURTLE_ABOVE_1 3
#define TURTLE_ABOVE_2 -3
#define TURTLE_SINKING_1 2
#define TURTLE_SINKING_2 -2
#define TURTLE_ALMOST_SUNK_1 1
#define TURTLE_ALMOST_SUNK_2 -1
#define TURTLE_SUNK 0
#define TURTLE_LOG 4
#define LONG_LOG_L LONG_LOG_IMAGE_SIZE*2//233

typedef struct
{
    POS pos;
    int length;
    float speed;
} LOG;

typedef struct {
    //float trash;
    POS pos;
    float length;
    float speed;
    int divingstate;
    int timer;
} TURTLES;

typedef struct {
    POS pos;
    int length;
    float speed;
    int log;
} SNEK;

//Inicializa los logs dependeindo del nivel
LOG* logs_init(unsigned int level);

//Inicializa tortugas dependiendo del nivel
TURTLES* turtles_init(unsigned int level);

//Mueve los logs
void log_update(LOG* logs, unsigned int amount, TURTLES* turtles, unsigned int turtlesamount);

//Mueve, sumerge, y levanta las tortugas
void turtle_update(TURTLES* turtles, unsigned int amount);

//Inicializa la serpiente
SNEK* snek_init (unsigned int level);

//Mueve la serpiente
void snek_update (SNEK* snek, LOG* logs, int amount, int shortlogamount, int longlogamount);

//Reaparece la serpiente
void respawn_snek (SNEK* snek, LOG* logs);

#endif /* LOGS_H */


