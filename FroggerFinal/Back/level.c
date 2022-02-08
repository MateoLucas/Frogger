#include "level.h"
#include <stdlib.h>

void level_init(LEVEL* level_, unsigned int level_num) 
{   
    srand(time(NULL));
    level_->level = level_num;
    level_->cars = car_init(level_num);
    level_->logs = logs_init(level_num);
    level_->turtles = turtles_init(level_num);
    level_->sneks = snek_init(level_num);
    level_->timer = timer_init();    
    level_->bases = base_init();
    if (level_num == LEVEL_1)
        level_->frog = frog_init(LIVES,0);
    else 
        level_->frog = frog_init(level_->frog->lives,level_->frog->score);  
    if (level_num>LEVEL_5) {
        while(level_num>5) {
            level_num -=5;

        }
    }
    switch (level_num) {
    case LEVEL_1:
        level_->caramount = LEVEL_1_CARS1;
        level_->logamount = LEVEL_1_LOGS;
        level_->snekamount = LEVEL_1_SNEKS;
        level_->turtleamount = LEVEL_1_DIVING_TURTLES;
        break;
    case LEVEL_2:
        level_->caramount = LEVEL_2_CARS;
        level_->logamount = LEVEL_2_LOGS;
        level_->snekamount = LEVEL_2_SNEKS;
        level_->turtleamount = LEVEL_2_DIVING_TURTLES;
        break;
    case LEVEL_3:
        level_->caramount = LEVEL_3_CARS;
        level_->logamount = LEVEL_3_LOGS;
        level_->snekamount = LEVEL_3_SNEKS;
        level_->turtleamount = LEVEL_3_DIVING_TURTLES;
        level_->shortlogamount= LEVEL_3_SHORT_LOGS;
        level_->longlogamount = LEVEL_3_LONG_LOGS;
        break;    
    case LEVEL_4:
        level_->caramount = LEVEL_4_CARS;
        level_->logamount = LEVEL_4_LOGS;
        level_->snekamount = LEVEL_4_SNEKS;
        level_->turtleamount = LEVEL_4_DIVING_TURTLES;
        level_->shortlogamount= LEVEL_4_SHORT_LOGS;
        level_->longlogamount = LEVEL_4_LONG_LOGS;
        break;    
    case LEVEL_5:
        level_->caramount = LEVEL_5_CARS;
        level_->logamount = LEVEL_5_LOGS;
        level_->snekamount = LEVEL_5_SNEKS;
        level_->turtleamount = LEVEL_5_DIVING_TURTLES;
        level_->shortlogamount= LEVEL_5_SHORT_LOGS;
        level_->longlogamount = LEVEL_5_LONG_LOGS;
        break;    
    default:
        break;
    }
}
//Liberar la memoria heap pedida para las instancias de los elementos 
void free_level_heap(LEVEL* level) {
    if (level->cars!=NULL)
        free(level->cars);
    if (level->logs!=NULL)
        free(level->logs);
    if (level->turtles!=NULL)
        free(level->turtles);
    if (level->bases!=NULL)
        free(level->bases);
    if (level->sneks!=NULL)
        free(level->sneks);
    return;
}
//Llama a los updates de los elementos
bool level_update(LEVEL* level) 
{
    bool ret = false;
    car_update(level->cars, level->caramount);
    log_update(level->logs, level->logamount, level->turtles, level->turtleamount);
    turtle_update(level->turtles, level->turtleamount);
    snek_update(level->sneks,level->logs,level->snekamount,level->shortlogamount,level->longlogamount);
    level->timer.countdown = get_countdown(level->timer);
    if (finishline(level->bases, &(level->timer), level->frog, level->level)) {
        free_level_heap(level);
        level->level+=1;
        level_init(level, level->level);
    }
    frog_update(level->turtles,level->frog, level->logs, level->cars,level->sneks,level->snekamount,level->caramount,level->logamount,level->turtleamount);
    if (level->frog->lives<=0||level->timer.countdown<=0) {
        ret = true;
    }
    return ret;
        
}

void level_timer_fix(LEVEL* level) 
{
    float max = level->timer.countdown;
    level->timer = timer_init();
    level->timer.max_time = max;
    return;
}

void frog_jump(FROG* frog, int direc)
{
    if(frog->jumping < 1)
    {
        frog->jumping = 1;
        frog->direc = direc;
    }
}