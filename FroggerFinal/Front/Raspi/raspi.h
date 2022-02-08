/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef RASPI_H
#define RASPI_H
#include "disdrv.h"
#include "joydrv.h"

#include "../../Back/level.h"

#include "termlib.h"
#define MENU_RESUME 1
#define MENU_NEW 2
#define MENU_LOAD 3
#define MENU_SAVE 4
#define MENU_QUIT 5
#define SCREEN_SW 16
#define SCREEN_W 16
#define MENU_RESUME 1
#define TURTLES_FLICKER_SPEED 2
#define FLY_FLICKER_SPEED 20
#define FROG_FLICKER_SPEED 2
#define MENU_RESUME 1
#define MENU_NEW 2
#define MENU_LOAD 3
#define MENU_SAVE 4
#define MENU_QUIT 5
#define TURTLES_FLICKER_SPEED 2
//Elementos del menu
enum{NEW_GAME, SAVE_GAME, LOAD_GAME, CONTINUE_GAME, QUIT_GAME, CONTINUE_MENU};
//Posibles entradas del joystick
enum{PAUSE, UP, DOWN, LEFT, RIGHT, NONE};
enum{KEY_PRESSED, NO_KEY_PRESSED};

//Cantidad de caracteres a imprimr
#define MAX_SCORE_CHARS 4
#define CYCLE 100
#define NUM_WIDTH 3
//Se asegura que las impresines fuera de pantalla no se ejecuten
void rasp_disp_write(dcoord_t pos, dlevel_t val);
//Dibuja el fondo de pantalla (calle y agua)
void draw_background();

//Imprime la rana titilante
void draw_frog(FROG*const frog);

//Elimina la instancia de la rana anterior
void delete_frog_area(FROG*const frog);

//Dibuja los autos
void draw_car(CAR*const car);

//Dibuja los logs en negro sobre el agua
void draw_log(LOG*const log);

//Dibuja las tortugas
void draw_turtle(TURTLES*const turtles);

//Dibua la serpiente
void draw_snek(SNEK*const snek);

//Dibuja las vidas y el tiempo
void draw_HUD(LEVEL*const level);

//Dibuja un punto prendido o apagado
void menu_point_draw(int x, int y, bool on);

//Dibuja la R del menu
void draw_resume(int x, int y, bool selected);

//Dibuja la N del menu
void draw_new(int x, int y, int selected);

//Dibuja la L del menu
void draw_load(int x, int y, bool selected);

//Dibuja la S del menu
void draw_save(int x, int y, bool selected);

//Dibuja la Q del menu
void draw_quit(int x, int y, bool selected);

//Calcula "a" a la pontencia de "b"
int powerOf(int a, int b);

//Pasa un int a  un array separado en digitos. 
void int2arr(int number,int* string);

//Impime las letras del menu y el puntaje
void print_menu(bool playing, bool first_time, FROG* frog, int index);

//Imprime el juego
void print_game(LEVEL*const level);

//Limpia la pantalla a la salida del menu
void quit_menu();

//Inicializa los graficos
void init_graphics();
#endif