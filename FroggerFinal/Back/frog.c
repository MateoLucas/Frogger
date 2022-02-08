#include "frog.h"

FROG* frog_init(int lives, int  score)
{
    FROG* frog;
    frog = (FROG*)malloc(sizeof(FROG));
    frog->lives = lives;
    frog->score = score;
    frog->direc = FRONT_DIR;
    frog->jumping = 0;
    frog->pos.lane = LANES_N;
    frog->pos.x = BUFFER_W/2;   
    frog->lowest_lane = LANES_N;
    return frog;
}

#define LANE_POINTS 10
void frog_update(TURTLES* turtles, FROG* frog, LOG* log, CAR* car,SNEK* sneks, int snekamount, int carsamount, int logsamount, int turtlesamount)//,FLY* fly) //agregar consts
{
    
     if(frog->pos.lane >= MIDDLE_LANE)
     {
         //check cars
         int i;
         
         for(i=0;i< carsamount;i++)
         {
             if(collision(frog->pos, FROG_W, car[i].pos, car[i].length))
             {
                frog->lives--; 
                frog->pos.lane = LANES_N;
             }
         }
         for(i=0;i< snekamount;i++)
         {
             if(collision(frog->pos, FROG_W, sneks[i].pos, sneks[i].length))
             {
                frog->lives--; 
                frog->pos.lane = LANES_N;
             }
         }
     }
     else if(frog->pos.lane <= MIDDLE_LANE && frog->pos.lane != FIRST_LANE)
     {
        //check logs
        int i;
        bool floating = false;
        for(i=0;i< logsamount ;i++)
        {
            if(collision(frog->pos, FROG_W, log[i].pos, log[i].length))
            {
               floating = true;
               if( frog->pos.x + log[i].speed + FROG_W < BUFFER_W && frog->pos.x + log[i].speed > 0)
               {
                   frog->pos.x += log[i].speed;  
               }
            }
        }
        
        for(i=0;i< turtlesamount ;i++)
        {
            if(collision(frog->pos, FROG_W, turtles[i].pos, turtles[i].length)) {
                if( frog->pos.x + turtles[i].speed + FROG_W < BUFFER_W && frog->pos.x + turtles[i].speed > 0)
                   {
                       frog->pos.x += turtles[i].speed;  
                   }
                if (turtles[i].length==CROC_L||turtles[i].length==CROC_L_OPEN) {
                    floating = true;
                }
                else if (turtles[i].divingstate){
                    floating = true;
                }
            }

        }

        if(!floating)
        {
            frog->lives--; 
            frog->pos.lane = LANES_N;
        }
     }
    if (frog->lowest_lane > frog->pos.lane) {
        frog->lowest_lane = frog->pos.lane;
        frog->score += LANE_POINTS;
    }
    //Cuando se pide a la rana que salte, esta seccion de codigo se encarga de moverla
     //Se pide que la rana salte poniendo frog_jumping en 1 para inicializar el salto
    if(frog->jumping != 0)
    {

        frog->jumping++;
        if(frog->jumping == JUMPING_FRAMES/2)
        {

            if(frog->direc == FRONT_DIR)
            {
                if(frog->pos.lane > 0)
                {
                    frog->pos.lane--;
                    
                }
            }
            if(frog->direc == BACK_DIR)
            {
                if(frog->pos.lane < LANES_N)
                {
                    frog->pos.lane++;
                }
            }
            if(frog->direc == RIGHT_DIR)
            {
                if(frog->pos.x + LANE_W/3 <= BUFFER_W)
                {
                    frog->pos.x += FROG_J_H;
                }
            }
            if(frog->direc == LEFT_DIR)
            {
                if(frog->pos.x - FROG_J_H/2 >= 0)
                {
                    frog->pos.x -= FROG_J_H;
                }
            }
        }
        if(frog->jumping > JUMPING_FRAMES)
        {
            frog->jumping = 0;
        }
    } 
     
}

