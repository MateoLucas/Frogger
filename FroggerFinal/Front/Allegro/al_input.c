

#include "al_input.h"
#include <stdio.h>

unsigned char key[ALLEGRO_KEY_MAX];
//Cola de eventos
ALLEGRO_EVENT_QUEUE* queue;

void init_queue()
{
    queue = al_create_event_queue();
    if(queue == NULL)
    {
        printf("Queue failed to initialize\n");
    }
}

ALLEGRO_EVENT_QUEUE* get_queue()
{
    return queue;
}


ALLEGRO_TIMER* timer;
void init_timer()
{
    timer = al_create_timer(1.0 / FPS);
    al_start_timer(timer);
    if(timer == NULL)
    {
        printf("Timer failed to initialize\n");
    }
}

ALLEGRO_EVENT event;

void init_event()
{
    al_register_event_source(queue, al_get_keyboard_event_source());
    //al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
}

ALLEGRO_EVENT* get_event_p()
{
    return &event;
}

void init_input() {
    init_queue();
    memset(key, 0, sizeof(key));
    init_timer();
    init_event();            
}

int menu(bool playing, bool first_time, int* index)//, unsigned char* key)
{     
    int ret = CONTINUE_MENU;
    static int delay = 0;
    delay++;
    al_get_next_event(get_queue(), get_event_p());
    switch(get_event_p()->type)
    {
        case ALLEGRO_EVENT_TIMER:

            if(key[ALLEGRO_KEY_UP]) {
                if(*index > NEW_GAME && delay > MENU_DELAY) {                    
                    *index-=1;
                    delay = 0;
                }
            }
            else if(key[ALLEGRO_KEY_DOWN])
            {   
                if(*index < QUIT_GAME && delay > MENU_DELAY) {
                    *index+=1;
                    delay = 0;
                }
            }     
            else if(key[ALLEGRO_KEY_ENTER])
                ret = *index;
            else
                ret = CONTINUE_MENU;
            break;
        
  
        }
        keyboard_update(get_event_p(), key);
        if (ret == QUIT_GAME) 
        {
            destroy_allegro();
        }
        return ret;
}

int game(int* key_pressed, bool* redraw) {

    int ret = NO_KEY_PRESSED;

    al_get_next_event(queue, &event);
    switch(event.type) {
            case ALLEGRO_EVENT_TIMER:
             
                        if(key[ALLEGRO_KEY_LEFT])
                        {   
                            *key_pressed = LEFT;                          
                        }
                        else if(key[ALLEGRO_KEY_RIGHT])
                        {
                            *key_pressed = RIGHT;
                        }
                        else if(key[ALLEGRO_KEY_UP])
                        {;
                            *key_pressed = UP;
                        }
                        else if(key[ALLEGRO_KEY_DOWN])
                        {
                            *key_pressed = DOWN;
                            
                        }
                        else if (key[ALLEGRO_KEY_P]) {
                            *key_pressed = PAUSE;
                        }
                        else
                            *key_pressed = NONE;
                        *redraw = true;
                        ret = KEY_PRESSED;
                        break;

    }
    keyboard_update(&event, key);
    return ret;
}

void keyboard_update(ALLEGRO_EVENT* event, unsigned char* key)
{
    switch(event->type)
    {
        case ALLEGRO_EVENT_TIMER:
            for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                key[i] &= KEY_SEEN;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            key[event->keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            key[event->keyboard.keycode] &= KEY_RELEASED;
            break;
    }
}

bool redraw_func(bool redraw) 
{
    return (redraw && al_is_event_queue_empty(queue));
}