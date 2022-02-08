


#ifndef LEVEL_H
#define LEVEL_H

#include "finishline.h"

//LEVEL tiene punteros a las estructuras claves del juego
typedef struct {
    unsigned int level;
    int caramount;
    int turtleamount;
    int logamount;
    int longlogamount;
    int shortlogamount;
    int snekamount;
    TIME timer;
    FROG* frog;
    CAR* cars;
    LOG* logs;
    TURTLES* turtles;
    SNEK* sneks;
    BASE* bases;
} LEVEL;

//Dependiendo del niviel inicializa todos los elemento de LEVEL
void level_init(LEVEL* level_, unsigned int level_num);

//Llama a las funciones que actualizan todos los elementos del nivel
bool level_update(LEVEL* level);

//Libera la maemeoria utilizada
void free_level_heap(LEVEL* level);

//Restablece el tiempo restanrte de la rana despues de una pausa
void level_timer_fix(LEVEL* level);

//Indicar que la rana tiene que saltar. frog_update se encarga de moverla
void frog_jump(FROG* frog, int direc);
#endif