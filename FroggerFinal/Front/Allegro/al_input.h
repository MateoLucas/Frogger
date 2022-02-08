/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef AL_INPUT_H
#define AL_INPUT_H


#include "allegro.h"

#define MENU_DELAY 50
#define FPS 60.0

//init_queue inicializa la cola de eventos
void init_queue();

//get_queue es un "getter" para pasar la cola de eventos a otros archivos
ALLEGRO_EVENT_QUEUE* get_queue();

//Inicializa el temporizador. Lo crea con la macro FPS y lo inicia 
void init_timer();

//Registra las fuentes de los eventos (teclado, mouse, etc..)
void init_event();

//"getter" del puntero a un ALLEGRO_EVENT
ALLEGRO_EVENT* get_event_p();

// Llama a los inicializadores del timer, el teclado, la cola de eventos, y los eventos
void init_input();

//Accede a la cola de eventos, rescata eventos, y segun estos, modifica el índice del menu
int menu(bool playing, bool first_time, int* index);

//Actualiza el estado del teclado
void keyboard_update(ALLEGRO_EVENT* event, unsigned char* key);

//Accede a la cola de eventos, rescata eventos, y segun estos, devuelve que accion en el menu debe ocurrir
int game(int* key_pressed, bool* redraw);

//Devuelve TRUE si hay que re-imprimir en pantalla dependiendo de si la cola de eventos
//esta vacia y de si el timer accionó
bool redraw_func(bool redraw);

#endif /* AL_INPUT_H */


