

/*
 * void joy_init(void);
 * int joy_update(void);
 * jcoord_t joy_get_coord(void);
 * jswitch_t joy_get_switch(void);
 * 
 * void disp_init(void);
 * void disp_clear(void);
 * void disp_write(dcoord_t coord, dlevel_t val);
 * void disp_update(void);
 * 
typedef struct {
    int8_t x;
    int8_t y;
} jcoord_t;
 * 
 * typedef struct {
    uint8_t x;		//coordenada x del display  
    uint8_t y;		//coordenada y del display 
} dcoord_t;
*/

#include "raspi.h"
#include <stdlib.h>
#include <stdio.h>

void rasp_disp_write(dcoord_t pos, dlevel_t val)
{
    if(pos.x >= 0 && pos.x <= BUFFER_W)
    {
            disp_write(pos, val);
    }
}
void draw_background()
{
    //disp_clear();
    dcoord_t pos;
    int i,j;
    for(i=0;i<SCREEN_W/2;i++)
    {
        for(j=0;j<SCREEN_W;j++)
        {
            pos.x= j;
            pos.y=i;
            rasp_disp_write(pos,D_ON);
        }
    }
}


void draw_frog(FROG*const frog)
{
    static int flicker = 0;
    flicker++;
    static bool state = true;
    dcoord_t pos;
    pos.x = frog->pos.x;
    pos.y = frog->pos.lane;
    //Titilea la rana para que sea identificable en la raspi
    if(flicker >= FROG_FLICKER_SPEED)
    {
        state = !state;
        flicker=0;
    }
    
    if(state)
    {
        rasp_disp_write(pos,D_ON);
    }
    else
    {
        rasp_disp_write(pos,D_OFF);
    }

    
}  
void delete_frog_area(FROG*const frog)
{
    dcoord_t del_pos;
    del_pos.x = frog->pos.x;
    del_pos.y = frog->pos.lane;
    del_pos.x++;
    if (del_pos.x >= 0 && del_pos.x < SCREEN_W)
        rasp_disp_write(del_pos,D_OFF);
    del_pos.x--;
    del_pos.x--;
    if (del_pos.x >= 0 && del_pos.x < SCREEN_W)
        rasp_disp_write(del_pos,D_OFF);
    del_pos.x++;
    del_pos.y++;
    if (del_pos.x >= 0 && del_pos.x < SCREEN_W)
        rasp_disp_write(del_pos,D_OFF);
    del_pos.y--;
    del_pos.y--;
    if (del_pos.x >= 0 && del_pos.x < SCREEN_W)
        rasp_disp_write(del_pos,D_OFF);
}


void draw_bases(BASE* bases) {
    for (int i=0; i<BASE_NUM; i++) {
        dcoord_t pos;
        pos.x = CORRECCION + BASE_S*i + BASE_D*i;
        pos.y = 1; 
        if (!bases[i].used) {            
            rasp_disp_write(pos,D_OFF);
            pos.x++;
            pos.y++;
            rasp_disp_write(pos,D_OFF);
        }
        else
        {
            pos.x++;
            pos.y++;
        }
        if (!bases[i].obj) {
            pos.x--;
            disp_write(pos,D_OFF);
            pos.x++;
            pos.y--;
            rasp_disp_write(pos,D_OFF);           
        }
        pos.x = CORRECCION + BASE_S*i + BASE_D*i;
        pos.y = 1; 
        if (bases[i].used) {            
            rasp_disp_write(pos,D_ON);
            pos.x++;
            pos.y++;
            rasp_disp_write(pos,D_ON);
            pos.x--;
            rasp_disp_write(pos,D_ON);
            pos.x++;
            pos.y--;
            rasp_disp_write(pos,D_ON);
        }
        if (bases[i].obj) {
            pos.x--;
            rasp_disp_write(pos,D_ON);
            pos.x++;
            pos.y--;
            rasp_disp_write(pos,D_ON);           
        }
    }
}   



void draw_car(CAR*const car)
{    
    dcoord_t pos;
    dcoord_t aux_pos;
    
    int j = 0;
    if (car->pos.x<0)
        j = car->pos.x;
    
    
    pos.x = car->pos.x;
    pos.y = car->pos.lane;             

    aux_pos.y = car->pos.lane;  
    
    
    
     
    if (car->speed > 0)
    {
        if (pos.x<=0) {
            aux_pos.x = BUFFER_W;
        }
        else
            aux_pos.x = car->pos.x-1;
    }
    else
    {   
        if (pos.x>=BUFFER_W) {
            aux_pos.x = 0;
        }
        else {
            aux_pos.x = car->length + car->pos.x;
        }
    }              
    for(int i=0;i<car->length+j;i++)
    {       
        if(pos.x >= 0 && pos.x <= BUFFER_W) {
            rasp_disp_write(pos,D_ON);
            pos.x++; //para encender el auto entero
        }      
    }
    if (aux_pos.x >= 0 && aux_pos.x <= BUFFER_W)
        {
            rasp_disp_write(aux_pos,D_OFF);
        }  
}

void draw_log(LOG*const log)
{
    int x = 0;
    dcoord_t pos;
    dcoord_t aux_pos;
    if (log->pos.x<0) {
        x = log->pos.x;
    }
    pos.x = log->pos.x;
    pos.y = log->pos.lane;

    aux_pos.y = log->pos.lane;   
    
    if (log->speed > 0){
        if (pos.x<=0) {
            aux_pos.x = BUFFER_W;
        }
        else
            aux_pos.x  = log->pos.x-1;
    }
    else {
        if (pos.x>=BUFFER_W) {
            aux_pos.x = 0;
        }
        else
            aux_pos.x = log->length + log->pos.x;
    }
    if (aux_pos.x >= 0 && aux_pos.x < 16)
        rasp_disp_write(aux_pos,D_ON);
    for(int i=0;i<log->length + x;i++)
    {
        rasp_disp_write(pos, D_OFF);
        pos.x++; //para encender el auto entero
    }

}

void draw_turtle(TURTLES*const turtles)
{
    if (turtles->pos.lane==4 || turtles->pos.lane==7) {
        if(turtles->divingstate == 0)
        {
            return;//estan sumergidos
        }
        else if(turtles->divingstate == TURTLE_ABOVE_1 ||turtles->divingstate == TURTLE_ABOVE_2)
        {
            dcoord_t pos;
            pos.x = turtles->pos.x;
            pos.y = turtles->pos.lane;
            int i;
            for(i=0;i<turtles->length;i++)
            {
                if(pos.x >= 0 && pos.x <= BUFFER_W)
                    rasp_disp_write(pos,D_OFF);
                pos.x ++; //para encender el auto entero
            }
        }
        else if((turtles->divingstate < TURTLE_ABOVE_1 && turtles->divingstate > TURTLE_ABOVE_2))
        {
            static bool state = true;
            dcoord_t pos;
            pos.x = turtles->pos.x;
            pos.y = turtles->pos.lane;
            static int flicker = 0;
            flicker++;
            if(flicker >= TURTLES_FLICKER_SPEED)
            {
                flicker =0;
                state = !state;
            }
            if(state)
            {
                int i;
                for(i=0;i<turtles->length;i++)
                {
                    if(pos.x >= 0 && pos.x <= BUFFER_W)
                        rasp_disp_write(pos,D_OFF);
                    pos.x ++; //para encender el auto entero
                }
            }
            else
            {
                int i;
                for(i=0;i<turtles->length;i++)
                {
                    rasp_disp_write(pos, D_ON);
                    pos.x ++; //para encender el auto entero
                }
            }
        }
    }
    //croc
    else {
        int x = 0;
        dcoord_t pos;
        if (turtles->pos.x<0) {
            x = turtles->pos.x;
        }
        pos.x = turtles->pos.x + x;
        pos.y = turtles->pos.lane;
        int i;
        for(i=0;i<turtles->length + x;i++)
        {
            rasp_disp_write(pos,D_OFF);
            pos.x++; 
        }
    }
}
/*
void draw_snek(SNEK*const snek)
{
    dcoord_t pos;
    pos.x = snek->pos.x;    
    pos.y = snek->pos.lane;
    int i;
    for(i = 0;i<snek->length;i++)
    {
        if(!(i%2))
        {
            disp_write(pos,D_ON);
            pos.x++;
        }
        else if(i%2)
        {
            disp_write(pos,D_OFF);
            pos.x++;
        }
    }
}
*/
void draw_HUD(LEVEL*const level)
{
    dcoord_t pos;
    dcoord_t aux_pos;
    pos.y = FINAL_LANE;
    pos.x = 0;
    aux_pos.y = FINAL_LANE;
    aux_pos.x = LIVES-1;
    int f;
    for(f=level->frog->lives;f > 0;f--)
    {
        rasp_disp_write(pos,D_ON);
        pos.x++;
    }
    for(f=LIVES-level->frog->lives;f > 0;f--)
    {
        rasp_disp_write(aux_pos,D_OFF);
        aux_pos.x--;
    }

    pos.x = FINAL_LANE;
    aux_pos.x = FINAL_LANE - MAX_TIME/10;
    int time_hud = (level->timer.countdown) /10;
    for(f = time_hud; f > 0 ; f--)
    {
        rasp_disp_write(pos,D_ON);
        pos.x--;
    }
    for(f=(MAX_TIME/10)-time_hud;f > 0;f--)
    {
        rasp_disp_write(aux_pos,D_OFF);
        aux_pos.x++;
    }
}


void menu_point_draw(int x, int y, bool on)
{
    dcoord_t pos;
    pos.x= x;
    pos.y=y;
    if(on)
    {
        rasp_disp_write(pos,D_OFF);
    }
    else
    {
        rasp_disp_write(pos,D_ON);
    }
}

void draw_resume(int x, int y, bool selected)
{
    menu_point_draw(x,y,selected);
    menu_point_draw(x+1,y,selected);
    menu_point_draw(x+2,y,selected);
    
    menu_point_draw(x,y+1,selected);
    menu_point_draw(x+1,y+1,!selected);
    menu_point_draw(x+2,y+1,selected);
    
    menu_point_draw(x,y+2,selected);
    menu_point_draw(x+1,y+2,selected);
    menu_point_draw(x+2,y+2,selected);
    
    menu_point_draw(x,y+3,selected);
    menu_point_draw(x+1,y+3,selected);
    menu_point_draw(x+1,y+3,!selected);
    
    menu_point_draw(x,y+4,selected);
    menu_point_draw(x+1,y+4,!selected);
    menu_point_draw(x+2,y+4,selected);
}

void draw_new(int x, int y, int selected)
{
    menu_point_draw(x,y,selected);
    menu_point_draw(x+1,y,!selected);
    menu_point_draw(x+2,y,!selected);
    menu_point_draw(x+3,y,selected);
    
    menu_point_draw(x,y+1,selected);
    menu_point_draw(x+1,y+1,selected);
    menu_point_draw(x+2,y+1,!selected);
    menu_point_draw(x+3,y+1,selected);
    
    menu_point_draw(x,y+2,selected);
    menu_point_draw(x+1,y+2,!selected);
    menu_point_draw(x+2,y+2,selected);
    menu_point_draw(x+3,y+2,selected);
    
    menu_point_draw(x,y+3,selected);
    menu_point_draw(x+1,y+3,!selected);
    menu_point_draw(x+2,y+3,!selected);
    menu_point_draw(x+3,y+3,selected);
}

void draw_load(int x, int y, bool selected)
{
    menu_point_draw(x,y,selected);
    menu_point_draw(x+1,y,!selected);
    menu_point_draw(x+2,y,!selected);
    
    menu_point_draw(x,y+1,selected);
    menu_point_draw(x+1,y+1,!selected);
    menu_point_draw(x+2,y+1,!selected);
    
    menu_point_draw(x,y+2,selected);
    menu_point_draw(x+1,y+2,!selected);
    menu_point_draw(x+2,y+2,!selected);
    
    menu_point_draw(x,y+3,selected);
    menu_point_draw(x+1,y+3,selected);
    menu_point_draw(x+2,y+3,selected);

}

void draw_save(int x, int y, bool selected)
{
    menu_point_draw(x,y,selected);
    menu_point_draw(x+1,y,selected);
    menu_point_draw(x+2,y,selected);
    
    menu_point_draw(x,y+1,selected);
    menu_point_draw(x+1,y+1,!selected);
    menu_point_draw(x+2,y+1,!selected);
    
    menu_point_draw(x,y+2,selected);
    menu_point_draw(x+1,y+2,selected);
    menu_point_draw(x+2,y+2,selected);
    
    menu_point_draw(x,y+3,!selected);
    menu_point_draw(x+1,y+3,!selected);
    menu_point_draw(x+2,y+3,selected);
    
    menu_point_draw(x,y+4,selected);
    menu_point_draw(x+1,y+4,selected);
    menu_point_draw(x+2,y+4,selected);
}

void draw_quit(int x, int y, bool selected)
{
    menu_point_draw(x,y,selected);
    menu_point_draw(x+1,y,selected);
    menu_point_draw(x+2,y,selected);
    
    menu_point_draw(x,y+1,selected);
    menu_point_draw(x+1,y+1,!selected);
    menu_point_draw(x+2,y+1,selected);
    
    menu_point_draw(x,y+2,selected);
    menu_point_draw(x+1,y+2,!selected);
    menu_point_draw(x+2,y+2,selected);
    
    menu_point_draw(x,y+3,selected);
    menu_point_draw(x+1,y+3,selected);
    menu_point_draw(x+2,y+3,selected);
    
    menu_point_draw(x+3,y+4,selected);
}

void draw_0(int x, int y)
{
   menu_point_draw(x+1,y,false); 
   menu_point_draw(x,y+1,false); 
   menu_point_draw(x+2,y+1,false);  
   menu_point_draw(x+1,y+2,false); 
}

void draw_1(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x,y+1,false);
    menu_point_draw(x,y+2,false);
}

void draw_2(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x+1,y,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x+1,y+2,false);
    menu_point_draw(x+2,y+2,false);
}

void draw_3(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x,y+2,false);
}

void draw_4(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x,y+1,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x+2,y+1,false);
    menu_point_draw(x+2,y,false);
    menu_point_draw(x+2,y+2,false);
}

void draw_5(int x, int y)
{
    menu_point_draw(x+1,y,false);
    menu_point_draw(x+2,y,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x+1,y+2,false);
    menu_point_draw(x,y+2,false);
}

void draw_6(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x,y+1,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x,y+2,false);
    menu_point_draw(x+1,y+2,false);
}

void draw_7(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x+1,y,false);
    menu_point_draw(x+2,y,false);
    menu_point_draw(x+2,y+1,false);
    menu_point_draw(x+2,y+2,false);
}

void draw_8(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x+1,y,false);
    menu_point_draw(x,y+1,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x,y+2,false);
    menu_point_draw(x+1,y+2,false);
}

void draw_9(int x, int y)
{
    menu_point_draw(x,y,false);
    menu_point_draw(x+1,y,false);
    menu_point_draw(x,y+1,false);
    menu_point_draw(x+1,y+1,false);
    menu_point_draw(x+1,y+2,false);
}

void (*draw_num_func_array[10]) (int x, int y)= {draw_0,draw_1, draw_2, draw_3,draw_4,draw_5,draw_6,draw_7,draw_8,draw_9};

int powerOf(int a, int b)
{
    int c = a;
    int i;
    for(i=0; i<b;i++)
    {
        c *= a;
    }
    return c;
}

void int2arr(int number,int* string)
{
    int i;
    for(i = MAX_SCORE_CHARS; i>=0;i--)
    {
        string[i] =(number%10);
        number /= 10;
    }
}

void draw_score(int x, int y, int score)
{
    int score_array[MAX_SCORE_CHARS];
    int2arr(score,score_array);
    int i;
    for(i = 0; i < MAX_SCORE_CHARS;i++)
    {
        (*draw_num_func_array[score_array[i]]) (x, y);
        x += NUM_WIDTH+1;
    }
}

void print_menu(bool playing, bool first_time, FROG* frog, int index)
{
    draw_resume(10,0,(index == CONTINUE_GAME));
    draw_new(0,0,(index == NEW_GAME));
    draw_load(5,0,(index == LOAD_GAME));
    draw_save(0,6,(index == SAVE_GAME));
    draw_quit(10,6,(index == QUIT_GAME));
    if(!first_time) 
    {
        draw_score(0,FINAL_LANE-3,frog->score);
    }
    disp_update();    
}


void print_game(LEVEL*const level)
{
    static int hola = 0;
    hola++;
    delete_frog_area(level->frog);
    draw_background();  

    int i;
    for(i=0;i<level->caramount;i++)
    {
        draw_car(&(level->cars[i]));
    }

    for(i=0;i<level->logamount;i++)
    {
        draw_log(&(level->logs[i]));
    }
    for (i=0;i<level->turtleamount;i++) {
        draw_turtle(&(level->turtles[i]));
    }

    draw_bases(level->bases);
    draw_frog(level->frog);
    draw_HUD(level);
    disp_update();
}


void init_graphics() 
{
    disp_init();
}

void quit_menu() 
{
    disp_clear();
    disp_update();
}



