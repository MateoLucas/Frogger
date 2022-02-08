/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "position.h"

bool collision(POS pos1, int size1, POS pos2, int size2) {
    return ((pos1.lane == pos2.lane) && (((pos1.x <= pos2.x + size2) && (pos1.x + size1 >= pos2.x)) || ((pos1.x <=pos2.x +size2)&&(pos1.x + size1 >= pos2.x))));
}