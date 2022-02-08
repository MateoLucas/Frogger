
/* 
 * File:   timer.h
 * Author: Grupo
 *
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <time.h>

#define MAX_TIME 45

typedef struct{
    time_t base_time;
    time_t countdown;
    time_t max_time;
}TIME;

//guardan el tiempo restante para llegar a una base 
//y cosas necesarias para el funcionamiento correcto de la funcion
TIME timer_init(void);

//Devuelve la cantidad de tiempo que queda de la rana
double get_countdown(TIME timer);


#endif /* TIMER_H */

