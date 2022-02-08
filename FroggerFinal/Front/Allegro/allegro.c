#include "allegro.h"

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>




void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
bool initialize_allegro() {  //Funcion que inicializa todo allegro. No recibe nada. Devuelve un true si esta todo ok, false si hay error.

    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!");
        return false;
    }
    
    if (!al_init_image_addon()) {       // ADDON necesario para manejo de imagenes 
        fprintf(stderr, "Failed to initialize image addon!");
        return false;
    }

    if (!al_init_font_addon()) {        // ADDON necesario para manejo de fuentes 
        fprintf(stderr, "Failed to initialize font addon!");
        al_shutdown_image_addon();
        return false;
    }

    if (!al_init_primitives_addon()) {   // ADDON necesario para manejo de formas
        fprintf(stderr, "Failed to initialize primitives addon!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        return false;
    }

    if (!al_init_ttf_addon()) {        // ADDON necesario para manejo de fuentes 
        fprintf(stderr, "Failed to initialize ttf addon!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_install_audio()) {
        fprintf(stderr, "Failed to install audio!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        al_shutdown_ttf_addon();
        return false;
    }

    if (!al_init_acodec_addon()) {
        fprintf(stderr, "Failed to initialize acodec addon!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        al_shutdown_ttf_addon();
        al_uninstall_audio();
        return false;
    }

    if (!al_install_keyboard()) {
        fprintf(stderr, "Failed to install keyboard!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        al_shutdown_ttf_addon();
        al_uninstall_audio();
        return false;
    }

    if (!al_install_mouse()) {
        fprintf(stderr, "Failed to install mouse!");
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        al_shutdown_ttf_addon();
        al_uninstall_audio();
        al_uninstall_keyboard();
        return false;
    }


    return true;

}
ALLEGRO_DISPLAY* disp;//display
ALLEGRO_BITMAP* buffer;
ALLEGRO_FONT* font;



ALLEGRO_FONT *font;

ALLEGRO_BITMAP* back;
ALLEGRO_BITMAP* frog_image;
ALLEGRO_BITMAP* fast_car_image;
ALLEGRO_BITMAP* medium_car_image;
ALLEGRO_BITMAP* slow_car_image;
ALLEGRO_BITMAP* short_log_image;
ALLEGRO_BITMAP* medium_log_image;
ALLEGRO_BITMAP* long_log_image;
ALLEGRO_BITMAP* short_turtle_image;
ALLEGRO_BITMAP* long_turtle_image;
ALLEGRO_BITMAP* fly_image;
ALLEGRO_BITMAP* diving_turtles_long_1;
ALLEGRO_BITMAP* diving_turtles_long_2;
ALLEGRO_BITMAP* diving_turtles_short_1;
ALLEGRO_BITMAP* diving_turtles_short_2;
ALLEGRO_BITMAP* croc;
ALLEGRO_BITMAP* croc_open;
ALLEGRO_BITMAP* croc_short;
ALLEGRO_BITMAP* snek;
ALLEGRO_BITMAP* duck;



bool init_display()
{
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    disp = al_create_display(DISPLAY_W, DISPLAY_H);
    must_init(disp, "display");
    buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
    must_init(buffer, "bitmap buffer");
    font = al_create_builtin_font();
    must_init(font, "font");
    return true;
}




void destroy_allegro(void) 
{
    al_destroy_bitmap(back);
    al_destroy_bitmap(frog_image);
    al_destroy_bitmap(fast_car_image);
    al_destroy_bitmap(medium_car_image);
    al_destroy_bitmap(slow_car_image);
    al_destroy_bitmap(short_log_image);
    al_destroy_bitmap(medium_log_image);
    al_destroy_bitmap(long_log_image);
    al_destroy_bitmap(fly_image);
    al_destroy_bitmap(diving_turtles_long_1);
    al_destroy_bitmap(diving_turtles_long_2);
    al_destroy_bitmap(diving_turtles_short_1);
    al_destroy_bitmap(diving_turtles_short_2);
    al_destroy_bitmap(croc);
    al_destroy_bitmap(croc_open);
    al_destroy_bitmap(croc_short);
    al_destroy_bitmap(snek);
    al_destroy_bitmap(duck);
    al_destroy_bitmap(buffer);
    al_destroy_display(disp);
    al_shutdown_image_addon();
    //al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
    al_uninstall_audio();
    al_uninstall_mouse();
    al_uninstall_keyboard();
    
}

bool init_images()
{
    back = al_load_bitmap("Resources/background.png");
    if(back == NULL)
    {
        printf("bitmap load error back");
        return false;
    }
   
    frog_image = al_load_bitmap("Resources/frog.png");
    if(frog_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    fast_car_image = al_load_bitmap("Resources/autorapido.png");
    if(fast_car_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    medium_car_image = al_load_bitmap("Resources/autopromedio.png");
    if(medium_car_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    slow_car_image = al_load_bitmap("Resources/autolento.png");
    if(slow_car_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    short_log_image = al_load_bitmap("Resources/logcorto.png");
    if(short_log_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    medium_log_image = al_load_bitmap("Resources/logmediano.png");
    if(medium_log_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    long_log_image = al_load_bitmap("Resources/loglargo.png");
    if(long_log_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    short_turtle_image = al_load_bitmap("Resources/turtleshort(1).png");
    if(short_turtle_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    long_turtle_image = al_load_bitmap("Resources/turtlelong(1).png");
    if(long_turtle_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    fly_image = al_load_bitmap("Resources/fly.png");
    if(fly_image == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    diving_turtles_short_1= al_load_bitmap("Resources/turtledive1short.png");
    if(diving_turtles_short_1 == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    diving_turtles_short_2= al_load_bitmap("Resources/turtledive2short.png");
    if(diving_turtles_short_2 == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    diving_turtles_long_1= al_load_bitmap("Resources/turtledive1long.png");
    if(diving_turtles_long_1 == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    diving_turtles_long_2= al_load_bitmap("Resources/turtledive2long.png");
    if(diving_turtles_long_2 == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    croc= al_load_bitmap("Resources/croc.png");
    if(croc == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    croc_open= al_load_bitmap("Resources/croc2.png");
    if(croc_open == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    croc_short= al_load_bitmap("Resources/croc3.png");
    if(croc_short == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    snek= al_load_bitmap("Resources/snek.png");
    if(snek == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    duck= al_load_bitmap("Resources/duck.png");
    if(duck == NULL)
    {
        printf("bitmap load error");
        return false;
    }
    font = al_load_font ("Resources/Lato-Regular.ttf",FONT_SIZE,0);
    return true;
   
}

void draw_score(int score,int x, int y)
{
    al_draw_textf (font, WHITE, BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*6, ALLEGRO_ALIGN_CENTER, "Final score: %d", score);   
}


void print_menu(bool playing, bool first_time, FROG* frog, int index)
{

    
    al_set_target_bitmap(buffer);
    al_draw_bitmap(back, 0,0,0);

    if(index == NEW_GAME)
    {
        al_draw_text(
        font,
        al_map_rgb_f(1,1,1),
        BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING,
        ALLEGRO_ALIGN_CENTER,
        "NEW GAME"
        );
    }
    else
    {
        al_draw_text(
        font,
        RED,
        BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING,
        ALLEGRO_ALIGN_CENTER,
        "NEW GAME"
        );
    }

//    if(playing)
//    {
        if(index == SAVE_GAME)
        {
            al_draw_text(
            font,
            al_map_rgb_f(1,1,1),
            BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*2,
            ALLEGRO_ALIGN_CENTER,
            "SAVE GAME"
            );  
        }
        else 
        {
            al_draw_text(
            font,
            RED,
            BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*2,
            ALLEGRO_ALIGN_CENTER+MENU_SPACING,
            "SAVE GAME"
            ); 
        }
//    }
    if(index == LOAD_GAME)
    {
        al_draw_text(
        font,
        al_map_rgb_f(1,1,1),
        BUFFER_W / 2, (BUFFER_H / 2)+MENU_SPACING*3,
        ALLEGRO_ALIGN_CENTER,
        "LOAD GAME"
        );
    }
    else
    {
        al_draw_text(
        font,
        RED,
        BUFFER_W / 2, (BUFFER_H / 2)+MENU_SPACING*3,
        ALLEGRO_ALIGN_CENTER+MENU_SPACING,
        "LOAD GAME"
        );
    }
    if(index == CONTINUE_GAME)
    {
        al_draw_text(
        font,
        al_map_rgb_f(1,1,1),
        BUFFER_W / 2, (BUFFER_H /2)+MENU_SPACING*4 ,
        ALLEGRO_ALIGN_CENTER,
        "RESUME GAME"
        );
    }
    else
    {
        al_draw_text(
        font,
        RED,
        BUFFER_W / 2, (BUFFER_H /2)+MENU_SPACING*4 ,
        ALLEGRO_ALIGN_CENTER+MENU_SPACING,
        "RESUME GAME"
        );
    }

        if(index == QUIT_GAME)
        {
            al_draw_text(
            font,
            al_map_rgb_f(1,1,1),
            BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*5,
            ALLEGRO_ALIGN_CENTER,
            "QUIT GAME"
            );
        }
        else
        {
            al_draw_text(
            font,
            RED,
            BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*5,
            ALLEGRO_ALIGN_CENTER+MENU_SPACING,
            "QUIT GAME"
            );
        }
    if(!first_time) {
        al_draw_textf (font, WHITE, BUFFER_W / 2, BUFFER_H / 2 + MENU_SPACING*6, ALLEGRO_ALIGN_CENTER, "Final score: %d", frog->score);
    }
    al_set_target_backbuffer(disp);
    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISPLAY_W, DISPLAY_H, 0);
    al_flip_display();
 
            
}
void print_game(LEVEL* level)
{

    al_set_target_bitmap(buffer);
    al_draw_bitmap(back, 0,0,0);
    al_clear_to_color(al_map_rgb(0,0,0));

    //draws
    al_draw_bitmap(back,0,20,0);
    
    
    //Imprime los Logs y tortugas
    int i;
    for(i = 0; i < level->logamount; i++)
    {
        if(level->logs[i].length == SHORT_LOG_L)
        {
            al_draw_bitmap(short_log_image,level->logs[i].pos.x,(level->logs[i].pos.lane-1)*LANE_W,0);
        }
        if(level->logs[i].length == MEDIUM_LOG_L)
        {
             
            al_draw_bitmap(medium_log_image,level->logs[i].pos.x,(level->logs[i].pos.lane-1)*LANE_W,0);
        }
        if(level->logs[i].length == LONG_LOG_L)
        {
           
            al_draw_bitmap(long_log_image,level->logs[i].pos.x,((level->logs[i].pos.lane-1)*LANE_W),0);   
            al_draw_bitmap(long_log_image,level->logs[i].pos.x+LONG_LOG_IMAGE_SIZE,((level->logs[i].pos.lane-1)*LANE_W),0); 
        }
        if(level->logs[i].length == TRTLSHORT_L)
        {
           
            al_draw_bitmap(short_turtle_image,level->logs[i].pos.x,((level->logs[i].pos.lane-1)*LANE_W),0);          
        }
        if(level->logs[i].length == TRTLLONG_L)
        {
           
            al_draw_bitmap(long_turtle_image,level->logs[i].pos.x,((level->logs[i].pos.lane-1)*LANE_W),0); 
            
            
        }
        if(level->logs[i].length == DUCK_L)
        {
            if (level->logs[i].speed > 0)
                al_draw_bitmap(duck,level->logs[i].pos.x,((level->logs[i].pos.lane-1)*LANE_W),0);          
            else 
                al_draw_bitmap(duck,level->logs[i].pos.x,((level->logs[i].pos.lane-1)*LANE_W),ALLEGRO_FLIP_HORIZONTAL);
        }
        
    } 
    
    //Imprime las bases
    for (i=0;i<BASE_NUM;i++) {
        al_draw_filled_rectangle(CORRECCION+BASE_S*i+BASE_D*i, (0.5)*LANE_W, CORRECCION+BASE_S*i+BASE_D*i + BASE_S, (0.5)*LANE_W + BASE_S,al_map_rgb(255,98,100));
        if (level->bases[i].used) {
            al_draw_bitmap(frog_image, CORRECCION+BASE_S*(i+0.5)+BASE_D*i -FROG_W/2 ,0.75*LANE_W*1.5,0);
        }
        if (level->bases[i].obj) {
            if (level->level%2==0)
                al_draw_bitmap(croc_short, CORRECCION+BASE_S*(i+0.5)+BASE_D*i ,0.75*LANE_W*1.5,0);
            else
                al_draw_bitmap(fly_image, CORRECCION+BASE_S*(i+0.5)+BASE_D*i ,0.75*LANE_W*1.5,0);
        }
    }
    //Imprime los autos
    for(i = 0; i < level->caramount; i++)
    {
        
        if(level->cars[i].length == CARSLOWSIZE)
        {

            al_draw_bitmap(slow_car_image,level->cars[i].pos.x,(level->cars[i].pos.lane-1)*LANE_W,ALLEGRO_FLIP_HORIZONTAL);

        }
        if(level->cars[i].length == CARMEDIUMSIZE)
        {
            if (level->cars[i].speed > 0)
                al_draw_bitmap(medium_car_image,level->cars[i].pos.x,(level->cars[i].pos.lane-1)*LANE_W,0);
            else
                al_draw_bitmap(medium_car_image,level->cars[i].pos.x,(level->cars[i].pos.lane-1)*LANE_W,ALLEGRO_FLIP_HORIZONTAL);
        }
        if(level->cars[i].length == CARFASTSIZE)
        {
            al_draw_bitmap(fast_car_image,level->cars[i].pos.x,(level->cars[i].pos.lane-1)*LANE_W,0);
        }
    }

    //Imprime las tortugas
    for(i=0; i < level->turtleamount; i++)
    {
        if(level->turtles[i].length == TRTLSHORT_L)
        {
            switch (level->turtles[i].divingstate) {
            case TURTLE_ABOVE_1:
            case TURTLE_ABOVE_2:
                al_draw_bitmap(short_turtle_image,level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0);   
                break;
            case TURTLE_SINKING_1:
            case TURTLE_SINKING_2:
                al_draw_bitmap(diving_turtles_short_2, level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0); 
                break;
            case TURTLE_ALMOST_SUNK_1:
            case TURTLE_ALMOST_SUNK_2:
                al_draw_bitmap(diving_turtles_short_1, level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0); 
                break;
            default:
                break;
            }
        }
        if(level->turtles[i].length == TRTLLONG_L)
        {
            switch (level->turtles[i].divingstate) {
            case TURTLE_ABOVE_1:
            case TURTLE_ABOVE_2:
                al_draw_bitmap(long_turtle_image,level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0);   
                break;
            case TURTLE_SINKING_1:
            case TURTLE_SINKING_2:
                al_draw_bitmap(diving_turtles_long_2, level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0); 
                break;
            case TURTLE_ALMOST_SUNK_1:
            case TURTLE_ALMOST_SUNK_2:
                al_draw_bitmap(diving_turtles_long_1, level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0); 
                break;
            default:
                break;
            }      
        }
        if (level->turtles[i].length == CROC_L) {
            al_draw_bitmap(croc,level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),ALLEGRO_FLIP_HORIZONTAL);
        }
        if (level->turtles[i].length == CROC_L_OPEN) {
            al_draw_bitmap(croc_open,level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),ALLEGRO_FLIP_HORIZONTAL);
        }
        if (level->turtles[i].length == MEDIUM_LOG_L) {
            al_draw_bitmap(medium_log_image,level->turtles[i].pos.x,((level->turtles[i].pos.lane-1)*LANE_W),0);
        }
    }
    
    //Imprime las serpientes
    
    for (i=0;i<level->snekamount;i++) {
        if (((level->sneks[i].speed > 0)&&(level->sneks[i].pos.lane==MIDDLE_LANE))||level->sneks[i].speed > LOGSPD_F)
            al_draw_bitmap(snek,level->sneks[i].pos.x,(level->sneks[i].pos.lane-1)*LANE_W,0);
        else 
            al_draw_bitmap(snek,level->sneks[i].pos.x,(level->sneks[i].pos.lane-1)*LANE_W,ALLEGRO_FLIP_HORIZONTAL);
    }

    //Imprime la ranas
    switch(level->frog->direc)
    {  
        case FRONT_DIR:
            al_draw_bitmap(frog_image,level->frog->pos.x,((level->frog->pos.lane-1)*LANE_W)+FROG_L/2, ALLEGRO_FLIP_VERTICAL);
            break;
        case BACK_DIR:
            al_draw_bitmap(frog_image,level->frog->pos.x,((level->frog->pos.lane-1)*LANE_W)+FROG_L/2, 0);
            break;
        case LEFT_DIR:
            al_draw_rotated_bitmap(frog_image, FROG_L/2, FROG_W/2,level->frog->pos.x,(((level->frog->pos.lane-1)*LANE_W)+FROG_L/2), ALLEGRO_PI/2, 0);
            break;
        case RIGHT_DIR:
            al_draw_rotated_bitmap(frog_image, FROG_L/2, FROG_W/2,level->frog->pos.x +FROG_W/2,(((level->frog->pos.lane-1)*LANE_W)+2*FROG_L), 3*ALLEGRO_PI/2, 0);

            break;
    }
    
    //Imprime HUD
    al_draw_textf (font, WHITE, ESC_X*1.3 , 0, ALLEGRO_ALIGN_LEFT, "Timer: %ld", level->timer.countdown);
    al_draw_textf (font, WHITE, 0, 0, ALLEGRO_ALIGN_LEFT, "Lives: %d", level->frog->lives);
    al_draw_textf (font, WHITE, 0 , ESC_Y/2, ALLEGRO_ALIGN_LEFT, "Score: %d", level->frog->score);
    
    al_set_target_backbuffer(disp);
    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISPLAY_W, DISPLAY_H, 0);
    al_flip_display();
}


//Se escribe asi para debuguear con facilidad
void init_graphics() {
    if(!initialize_allegro() )//|| !init_display() || !init_images())
    {

    }
    if (!init_display()) {

    }
    if (!init_images()) {
      
    }            
}

void quit_menu()
{
    //al_draw_bitmap(back,0,20,0);
}