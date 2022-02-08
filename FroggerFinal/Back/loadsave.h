

#ifndef LOADSAVE_H
#define LOADSAVE_H

#include "level.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Guarda todos los elementos del LEVEL en un archivo.txt
bool save_game(LEVEL* level_);
//Carga del .txt el juego 
bool load_game(LEVEL* level_, bool first_time);

#endif /* LOADSAVE_H */

