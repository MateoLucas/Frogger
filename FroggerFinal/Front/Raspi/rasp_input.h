/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rasp_input.h
 * Author: mariano
 *
 * Created on January 26, 2022, 12:45 PM
 */

#ifndef RASP_INPUT_H
#define RASP_INPUT_H

#include "raspi.h"

#define MENU_DELAY 25
#define JOY_THREASHOLD 10
//Inicializa la entrada de datos de raspi
void init_input();
//Atrapa las entradas del joystick y emite a la señal al menu
int menu(bool playing, bool first_time, int* index);
//Atrapa las entradas y emite la señal al juego
int game(int* key_pressed, bool* redraw);
//Define si es hora de redibujar
bool redraw_func(bool redraw);

#endif /* RASP_INPUT_H */

