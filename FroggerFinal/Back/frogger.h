/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   frogger.h
 * Author: mariano
 *
 * Created on January 26, 2022, 11:36 AM
 */

#ifndef FROGGER_H
#define FROGGER_H
#include <stdio.h>
#ifdef RASPI
#include "../Front/Raspi/rasp_input.h"
#else
#include "../Front/Allegro/allegro.h"
#include "../Front/Allegro/al_input.h"
#endif

void frogger(void);

#endif /* FROGGER_H */

