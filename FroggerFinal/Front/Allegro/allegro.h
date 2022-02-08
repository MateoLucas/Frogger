
/* 
 * File:   allegro.h
 * Author: mateo
 *
 * Created on August 11, 2021, 1:51 PM
 */

#ifndef ALLEGRO_H
#define ALLEGRO_H

#include <stdbool.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "../../Back/level.h"
// --------------------------     colores      -------------------------- //
#define BLACK           al_map_rgb(14,14,14)
#define WHITE           al_map_rgb(255,255,255)
#define RED             al_map_rgb(255,0,0)
#define GREEN           al_map_rgb(0,155,0)
#define BLUE            al_map_rgb(0,0,155)
#define GREY            al_map_rgb(128, 128, 128)
#define YELLOW          al_map_rgb(255, 255, 0)

//Separación de las palabras en el menú
#define MENU_SPACING 50

//Altura de las letras
#define WORD_H 5

//Ancho del título
//#define TITLE_W 630

//
//#define MENU_PAUSE_SHIFT (BUFFER_H/2)

//Posición del título en pantalla
//#define TITLE_X ((BUFFER_W/2)-TITLE_W/2)
//#define TITLE_Y 200

//Posición del HUD en el juego
#define ESC_X BUFFER_W/10
#define ESC_Y BUFFER_H/6

#define FONT_SIZE 36
#define KEY_SEEN     1
#define KEY_RELEASED 2

//Elementos del Menú
enum{NEW_GAME, SAVE_GAME, LOAD_GAME, CONTINUE_GAME, QUIT_GAME, CONTINUE_MENU};

//Teclas que se usan para jugar
enum{PAUSE, UP, DOWN, LEFT, RIGHT, NONE};
enum{KEY_PRESSED, NO_KEY_PRESSED};

//Funcion que inicializa cualquier funcion y devuelve si se pudo o no
void must_init(bool test, const char *description);

//Inicializa Allegro5 con todas sus funciones
bool initialize_allegro();     

//Desinicializa Allegro5
void destroy_allegro(void);

//Inicializa el display
bool init_display();

//Inicializa las imagenes
bool init_images();

//Imprime en pantalla el menu
void print_menu(bool playing, bool first_time, FROG* frog, int index);

//Imprime el juego
void print_game(LEVEL* level);

//Sale del menu
void quit_menu();

//Llama a los inicializadores de allegro, las imagenes, y el display
void init_graphics ();

#endif /* ALLEGRO_H */

