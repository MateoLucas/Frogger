#include "loadsave.h"

bool save_game (LEVEL* level_) {
    FILE* file_ptr = fopen("save_game.txt","w");    
    
    fprintf(file_ptr, "%d\n", level_->level);
    
    fprintf(file_ptr, "%ld\n", level_->timer.countdown);
    
    fprintf(file_ptr, "%f ", level_->frog->pos.x);
    fprintf(file_ptr, "%d ", level_->frog->pos.lane);
    fprintf(file_ptr, "%d ", level_->frog->jumping);
    fprintf(file_ptr, "%d ", level_->frog->direc);
    fprintf(file_ptr, "%d ", level_->frog->lives);
    fprintf(file_ptr, "%d ", level_->frog->score);
    fprintf(file_ptr, "%d\n", level_->frog->lowest_lane);
    
    for (int i = 0; i < level_->caramount; i++) {
        fprintf(file_ptr, "%f ", level_->cars[i].pos.x);
        fprintf(file_ptr, "%d\n", level_->cars[i].pos.lane);
    }
    
    for (int i = 0; i < level_->logamount; i++) {
        fprintf(file_ptr, "%f ", level_->logs[i].pos.x);
        fprintf(file_ptr, "%d\n", level_->logs[i].pos.lane);
    }
    
    for (int i = 0; i < level_->turtleamount; i++) {
        fprintf(file_ptr, "%f ", level_->turtles[i].pos.x);
        fprintf(file_ptr, "%d ", level_->turtles[i].pos.lane);
        fprintf(file_ptr, "%f ", level_->turtles[i].length);
        fprintf(file_ptr, "%d ", level_->turtles[i].divingstate);
        fprintf(file_ptr, "%d\n", level_->turtles[i].timer);
    }
    
    for (int i = 0; i < level_->snekamount; i++) {
        fprintf(file_ptr, "%f ", level_->sneks[i].pos.x);
        fprintf(file_ptr, "%d ", level_->sneks[i].pos.lane);
        fprintf(file_ptr, "%f\n", level_->sneks[i].speed);
    }
    
    for (int i = 0; i < BASE_NUM; i++) {
        fprintf(file_ptr, "%d ", level_->bases[i].used);
        fprintf(file_ptr, "%d\n", level_->bases[i].obj);
    }
    
    fclose(file_ptr);
    return true;   
}

bool load_game(LEVEL* level_, bool first_time) {
    char skip; //tira warning porque solo sirve para 
    //deshechar caractewres separadores
    FILE* file_ptr = fopen("save_game.txt","r");    
    fscanf(file_ptr,"%d",&level_->level);
    skip = fgetc(file_ptr);

    if (!first_time) {
        free_level_heap(level_);    
        free(level_->frog);
    }
    level_init(level_,level_->level);
    
    fscanf(file_ptr,"%ld",&level_->timer.max_time);
    skip = fgetc(file_ptr);

    
    fscanf(file_ptr,"%f",&level_->frog->pos.x);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->pos.lane);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->jumping);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->direc);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->lives);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->score);
    skip = fgetc(file_ptr);
    fscanf(file_ptr,"%d",&level_->frog->lowest_lane);
    skip = fgetc(file_ptr);
    
    for (int i = 0; i < level_->caramount; i++) {
        fscanf(file_ptr, "%f", &level_->cars[i].pos.x);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->cars[i].pos.lane);
        fgetc(file_ptr);
    }
    
    for (int i = 0; i < level_->logamount; i++) {
        fscanf(file_ptr, "%f", &level_->logs[i].pos.x);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->logs[i].pos.lane);
        fgetc(file_ptr);
    }
    
    for (int i = 0; i < level_->turtleamount; i++) {
        fscanf(file_ptr, "%f", &level_->turtles[i].pos.x);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->turtles[i].pos.lane);
        fgetc(file_ptr);
        fscanf(file_ptr, "%f", &level_->turtles[i].length);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->turtles[i].divingstate);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->turtles[i].timer);
        fgetc(file_ptr);
    }
    
    for (int i = 0; i < level_->snekamount; i++) {
        fscanf(file_ptr, "%f", &level_->sneks[i].pos.x);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", &level_->sneks[i].pos.lane);
        fgetc(file_ptr);
        fscanf(file_ptr, "%f", &level_->sneks[i].speed);
        fgetc(file_ptr);
    }
    
    for (int i = 0; i < BASE_NUM; i++) {
        fscanf(file_ptr, "%d",(int*)&level_->bases[i].used);
        fgetc(file_ptr);
        fscanf(file_ptr, "%d", (int*)&level_->bases[i].obj);
        fgetc(file_ptr);
    }
    fclose(file_ptr);
    return true;
}



