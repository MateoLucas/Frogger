/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "frogger.h"
#include "level.h"
#include "loadsave.h"


void frogger() {
    init_graphics();
    init_input();
    LEVEL level;
    bool exit = false;
    bool pause = true;
    bool playing = false;
    bool first_time = true;
    int key_pressed;
    
    bool done = false;

    bool redraw = true;
    
    int index = NEW_GAME;
    srand(time(NULL));
    //donde estoy donde quiewreo ir
    while(!exit)//menu
    { 
        if (pause) {
            if(redraw_func(redraw))
            { 
               print_menu(playing, first_time, level.frog, index);
               redraw = false;
            }           
            switch (menu(playing, first_time, &index)) {
                    case NEW_GAME:
                        level_init(&level,LEVEL_1);
                        playing = true;
                        pause = false;
                        first_time = false;
                        quit_menu();
                        break;
                    case CONTINUE_GAME:
                        if(playing)
                        {
                            pause = false;
                            level_timer_fix(&level);
                            quit_menu();
                        }
                        break;
                    case LOAD_GAME:
                        if(!load_game(&level,first_time))// load
                        {
                            printf("load error\n");
                        }
                        pause = false;
                        playing = true;
                        first_time = false;
                        quit_menu();
                        break;
                    case SAVE_GAME:
                        if((playing)&&!save_game(&level))
                        {
                            printf("save error\n");
                        }
                        break;
                    case QUIT_GAME:
                        exit = true;
                        if (!first_time) {
                            free_level_heap(&level);
                            free(level.frog);
                        }
                        quit_menu();
                        break;
                    default:
                        redraw = true;
                        break;
            }        
        }
        if (playing && !pause)//juego
        {
            
            playing = true;//cuando ganes/pierdas pones esto en false
            index = CONTINUE_GAME;
            if(redraw_func(redraw))
            {
                print_game(&level);
                redraw = false;
            }
            if (level_update(&level)) {
                playing=false;
                pause=true;
                quit_menu();
            }
            
            switch(game(&key_pressed, &redraw))
            {
                
                case KEY_PRESSED:
                    if(!pause)
                    {
                         
                        
                        if(key_pressed==LEFT) 
                            frog_jump(level.frog, LEFT_DIR);
                        else if(key_pressed==RIGHT)                             
                            frog_jump(level.frog, RIGHT_DIR);
                        else if(key_pressed==UP)  
                           frog_jump(level.frog, FRONT_DIR);
                        else if(key_pressed==DOWN)  
                           frog_jump(level.frog, BACK_DIR);
                        else if(key_pressed==PAUSE) {
                            pause = true;
                            quit_menu();
                        }
                        key_pressed = NONE;
                    }

                    break;

            }
            if(done)
            {
                break;
            }
        }
        
        if(done)
            break;
   
    }
}