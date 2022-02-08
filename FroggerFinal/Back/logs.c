/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "logs.h"
#include "level.h"

#include <stdlib.h>

void log_update(LOG* logs, unsigned int amount, TURTLES* turtles, unsigned int turtlesamount) {
    int size;
    for (int i = 0; i < amount; i++) {
        size = logs[i].length;
        logs[i].pos.x += logs[i].speed;
        if (logs[i].length!=DUCK_L) {
            if (logs[i].pos.x > BUFFER_W) {
                if (logs[i].speed > 0) {
                    logs[i].pos.x = -size;
                }
            }
            else if (logs[i].pos.x < -size) {
                if (logs[i].speed < 0) {
                    logs[i].pos.x = BUFFER_W;
                }
            }
        }

        else {
                while (logs[i].pos.x > BUFFER_W||logs[i].pos.x<-DUCK_L) {
                    int random = rand()%5;
                    switch (random) {
                    case 0:
                        logs[i].pos.lane = 6;
                        logs[i].pos.x = -DUCK_L;
                        logs[i].speed = DUCKSPD;
                        break;
                    case 1:
                        logs[i].pos.lane = 5;
                        logs[i].pos.x = -DUCK_L;
                        logs[i].speed = DUCKSPD;
                        break;
                    case 2:
                        logs[i].pos.lane = 3;
                        logs[i].pos.x = -DUCK_L;
                        logs[i].speed = DUCKSPD;
                        break;    
                    case 3:
                        //if (amount != LEVEL_3_LOGS) {
                            logs[i].pos.lane = 7;
                            logs[i].speed = -DUCKSPD;
                            logs[i].pos.x = BUFFER_W;
                        //}
                        break;
                    case 4:
                        //if (amount != LEVEL_3_LOGS) {
                            logs[i].pos.lane = 4;
                            logs[i].speed = -DUCKSPD;
                            logs[i].pos.x = BUFFER_W;
                        //}
                        break;
                    }
                }
                for (int j=0;j<amount; j++) {
                    while ((collision(logs[i].pos ,logs[i].length, logs[j].pos, logs[j].length))&&(logs[j].length!=DUCK_L)) {
                        int random = rand()%5;
                        switch (random) {
                        case 0:
                            logs[i].pos.lane = 6;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;
                        case 1:
                            logs[i].pos.lane = 5;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;
                        case 2:
                            logs[i].pos.lane = 3;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;    
                        case 3:
                                logs[i].pos.lane = 7;
                                logs[i].speed = -DUCKSPD;
                                logs[i].pos.x = BUFFER_W;
                            break;
                        case 4:
                                logs[i].pos.lane = 4;
                                logs[i].speed = -DUCKSPD;
                                logs[i].pos.x = BUFFER_W;
                            break;
                        }
                    }
                }
                for (int k=0;k<turtlesamount; k++) {
                    while ((collision(logs[i].pos ,logs[i].length, turtles[k].pos, turtles[k].length))) {
                        int random = rand()%5;
                        switch (random) {
                        case 0:
                            logs[i].pos.lane = 6;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;
                        case 1:
                            logs[i].pos.lane = 5;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;
                        case 2:
                            logs[i].pos.lane = 3;
                            logs[i].pos.x = -DUCK_L;
                            logs[i].speed = DUCKSPD;
                            break;    
                        case 3:
                                logs[i].pos.lane = 7;
                                logs[i].speed = -DUCKSPD;
                                logs[i].pos.x = BUFFER_W;
                            break;
                        case 4:
                                logs[i].pos.lane = 4;
                                logs[i].speed = -DUCKSPD;
                                logs[i].pos.x = BUFFER_W;
                            break;
                        }
                    }
                }

        }
    }
    return;
}

SNEK* snek_init (unsigned int level) {
    SNEK* sneks = NULL;
    int j = 0;
    if (level>LEVEL_5) {
        while(level>5) {
            level -=5;
            j++;
        }
    }
    switch (level) {
    case LEVEL_3:
        sneks = (SNEK*)malloc(LEVEL_3_SNEKS*(sizeof(SNEK)));
        sneks->pos.x = -SNEK_L;
        sneks->pos.lane = MIDDLE_LANE;
        sneks->speed = SNEKSPD*(1+j/3);
        sneks->log = -1;   
        sneks->length = SNEK_L;
        break;
    case LEVEL_4:
        sneks = (SNEK*)malloc(LEVEL_4_SNEKS*(sizeof(SNEK)));
        sneks->pos.x = -SNEK_L;
        sneks->pos.lane = MIDDLE_LANE;
        sneks->speed = SNEKSPD*(1+j/3);
        sneks->log = -1;   
        sneks->length = SNEK_L;
        break;
    case LEVEL_5:
        sneks = (SNEK*)malloc(LEVEL_5_SNEKS*(sizeof(SNEK)));
        sneks->pos.x = -SNEK_L;
        sneks->pos.lane = MIDDLE_LANE;
        sneks->speed = SNEKSPD*(1+j/3);
        sneks->log = -1;   
        sneks->length = SNEK_L;
        break;
    default:
        break;
    }
    return sneks;
}

void snek_update (SNEK* snek, LOG* logs, int amount, int shortlogamount, int longlogamount) {
    for (int i = 0;i<amount;i++) {
        snek[i].pos.x+=snek[i].speed;
            if ((snek[i].speed>0)&&snek[i].pos.x>BUFFER_W) {
                respawn_snek(&snek[i],&logs[shortlogamount]);
            }
            else if ((snek[i].pos.x<-SNEK_L)&&(snek[i].speed<0)) {
                respawn_snek(&snek[i],&logs[shortlogamount]);
            }
            else if (snek[i].pos.lane!=MIDDLE_LANE) {
                if (!collision(snek[i].pos, snek[i].length, logs[shortlogamount+snek->log].pos, logs[shortlogamount+snek->log].length)) {
                    if (snek->speed<logs[shortlogamount+snek->log].speed)
                        snek->speed += 2*SNEKSPD;
                    else
                        snek->speed -= 2*SNEKSPD;
                }
            }
    }
}

void respawn_snek (SNEK* snek, LOG* logs){
    if (snek->length==SNEK_L) {
        int random = rand()%3;
        switch (random) { 
        case 0:
            snek->pos.x = -SNEK_L;
            snek->pos.lane = MIDDLE_LANE;
            snek->speed = SNEKSPD;
            snek->log = -1;
            break;                
        case 1:
            snek->pos.x = BUFFER_W;
            snek->pos.lane = MIDDLE_LANE;
            snek->speed = -SNEKSPD;
            snek->log = -1;
            break;
        case 2:
            for (int i=0;i<LEVEL_1_LONG_LOGS;i++) {
                if (logs->pos.x < -SNEK_L) {
                    snek->pos.x = logs->pos.x;
                    snek->pos.lane = logs->pos.lane;
                    snek->speed = SNEKSPD+logs->speed;
                    snek->log = i;
                }
                logs++;
            }
            break;    
        default:
            break;
        }
    }
}

void turtle_update(TURTLES* turtles, unsigned int amount) {
    for (int i = 0; i < amount; i++) {
        turtles[i].timer--;
        turtles[i].pos.x += turtles[i].speed;
        if (turtles[i].pos.lane == TURTLE_LOG) {
            if (turtles[i].pos.x < -TRTLSHORT_L) {
                turtles[i].pos.x = BUFFER_W;
            }
        }
        else if (turtles[i].pos.lane == 7) {
            if (turtles[i].pos.x < -TRTLLONG_L) {
                turtles[i].pos.x = BUFFER_W;
            }
        }
        else {
            if (turtles[i].pos.x > BUFFER_W ) {
                turtles[i].pos.x = -MEDIUM_LOG_L;
                if (turtles[i].divingstate<TURTLE_LOG) {
                    turtles[i].divingstate=TURTLE_LOG;
                    turtles[i].length = MEDIUM_LOG_L;
                }
                else {
                    turtles[i].divingstate=TURTLE_ABOVE_1;   
                    turtles[i].timer = DIVE_TIMER;
                }
            }
            if (turtles[i].divingstate==TURTLE_LOG) {

            }
            else if (turtles[i].divingstate%2==0){
                turtles[i].length = CROC_L_OPEN;
            }
            else
                turtles[i].length = CROC_L;
        }
        if (!turtles[i].timer&&turtles[i].divingstate<TURTLE_LOG) {
            turtles[i].timer = DIVE_TIMER;
            turtles[i].divingstate--;
            if (turtles[i].divingstate == TURTLE_ABOVE_2)
                turtles[i].divingstate *= -1;
            
        }
        
    }
    return;
}


LOG* logs_init(unsigned int level) {
    LOG* logs;
    int j = 0;
    if (level>LEVEL_5) {
        while(level>5) {
            level -=5;
            j++;
        }
    }
    switch (level) {
    case LEVEL_1:
        logs = (LOG*)malloc(LEVEL_1_LOGS*(sizeof(LOG)));
        for (int i = 0; i < LEVEL_1_LOGS; i++) {
            if (i<LEVEL_1_SHORT_LOGS) {
                logs[i].pos.lane = 6;
                logs[i].pos.x = i*(BUFFER_W/3);
                logs[i].length = SHORT_LOG_L;
                logs[i].speed = LOGSPD_S;
            }
            else if (i<LEVEL_1_SHORT_LOGS+LEVEL_1_LONG_LOGS) {
                logs[i].pos.lane = 5;
                logs[i].pos.x = (BUFFER_W/2)*(i-2);
                logs[i].length = LONG_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_1_SHORT_LOGS+LEVEL_1_LONG_LOGS+LEVEL_1_MEDIUM_LOGS) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = (BUFFER_W/3)*(i-4);
                logs[i].length = MEDIUM_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_1_SHORT_LOGS+LEVEL_1_LONG_LOGS+LEVEL_1_MEDIUM_LOGS+LEVEL_1_LONG_TURTLES) {
                logs[i].pos.lane = 7;
                logs[i].pos.x = (i-8)*BUFFER_W/4;    
                logs[i].length = TRTLLONG_L;
                logs[i].speed = TRTLSPD_F;
            }
            else if (i<LEVEL_1_SHORT_LOGS+LEVEL_1_LONG_LOGS+LEVEL_1_MEDIUM_LOGS+LEVEL_1_LONG_TURTLES+LEVEL_1_SHORT_TURTLES) {
                logs[i].pos.lane = 4;
                logs[i].pos.x = (i-11)*BUFFER_W/4;
                logs[i].length = TRTLSHORT_L;
                logs[i].speed = TRTLSPD_S;
            }
            logs[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_2:
        logs = (LOG*)malloc(LEVEL_2_LOGS*(sizeof(LOG)));
        for (int i = 0; i < LEVEL_2_LOGS; i++) {
            if (i<LEVEL_2_SHORT_LOGS) {
                logs[i].pos.lane = 6;
                logs[i].pos.x = i*(BUFFER_W/3);
                logs[i].length = SHORT_LOG_L;
                logs[i].speed = LOGSPD_S;
            }
            else if (i<LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS) {
                logs[i].pos.lane = 5;
                logs[i].pos.x = (BUFFER_W/2)*(i-(LEVEL_2_SHORT_LOGS-1));
                logs[i].length = LONG_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_MEDIUM_LOGS) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = (BUFFER_W/3)*(i-(LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS-1));
                logs[i].length = MEDIUM_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_MEDIUM_LOGS+LEVEL_2_LONG_TURTLES) {
                logs[i].pos.lane = 7;
                logs[i].pos.x = (i-(LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_MEDIUM_LOGS-1))*BUFFER_W/4;    
                logs[i].length = TRTLLONG_L;
                logs[i].speed = TRTLSPD_F;
            }
            else if (i<LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_MEDIUM_LOGS+LEVEL_2_LONG_TURTLES+LEVEL_2_SHORT_TURTLES) {
                logs[i].pos.lane = 4;
                logs[i].pos.x = (i-(LEVEL_2_SHORT_LOGS+LEVEL_2_LONG_LOGS+LEVEL_2_MEDIUM_LOGS+LEVEL_2_LONG_TURTLES-1))*BUFFER_W/4;
                logs[i].length = TRTLSHORT_L;
                logs[i].speed = TRTLSPD_S;
            }
            logs[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_3:
        logs = (LOG*)malloc(LEVEL_3_LOGS*(sizeof(LOG)));
        for (int i = 0; i < LEVEL_3_LOGS; i++) {
            if (i<LEVEL_3_SHORT_LOGS) {
                logs[i].pos.lane = 6;
                logs[i].pos.x = i*(BUFFER_W/3);
                logs[i].length = SHORT_LOG_L;
                logs[i].speed = LOGSPD_S;
            }
            else if (i<LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS) {
                logs[i].pos.lane = 5;
                logs[i].pos.x = (BUFFER_W/2)*(i-(LEVEL_3_SHORT_LOGS-1));
                logs[i].length = LONG_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = (BUFFER_W/3)*(i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS-1));
                logs[i].length = MEDIUM_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES) {
                logs[i].pos.lane = 7;
                logs[i].pos.x = (i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS-1))*BUFFER_W/4;    
                logs[i].length = TRTLLONG_L;
                logs[i].speed = TRTLSPD_F;
            }
            else if (i<LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES) {
                logs[i].pos.lane = 4;
                logs[i].pos.x = (i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES-1))*BUFFER_W/4;
                logs[i].length = TRTLSHORT_L;
                logs[i].speed = TRTLSPD_S;
            }
            else if(i<LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES+LEVEL_3_DUCK) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = 0;//(i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES-1))*BUFFER_W/5;
                logs[i].length = DUCK_L;
                logs[i].speed = DUCKSPD;
            }
            logs[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_4:
        logs = (LOG*)malloc(LEVEL_4_LOGS*(sizeof(LOG)));
        for (int i = 0; i < LEVEL_4_LOGS; i++) {
            if (i<LEVEL_4_SHORT_LOGS) {
                logs[i].pos.lane = 6;
                logs[i].pos.x = i*(BUFFER_W/3);
                logs[i].length = SHORT_LOG_L;
                logs[i].speed = LOGSPD_S;
            }
            else if (i<LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS) {
                logs[i].pos.lane = 5;
                logs[i].pos.x = (BUFFER_W/2)*(i-(LEVEL_4_SHORT_LOGS-1));
                logs[i].length = LONG_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = (BUFFER_W/3)*(i-(LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS-1));
                logs[i].length = MEDIUM_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS+LEVEL_4_LONG_TURTLES) {
                logs[i].pos.lane = 7;
                logs[i].pos.x = (i-(LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS-1))*BUFFER_W/4;    
                logs[i].length = TRTLLONG_L;
                logs[i].speed = TRTLSPD_F;
            }
            else if (i<LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS+LEVEL_4_LONG_TURTLES+LEVEL_4_SHORT_TURTLES) {
                logs[i].pos.lane = 4;
                logs[i].pos.x = (i-(LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS+LEVEL_4_LONG_TURTLES-1))*BUFFER_W/4;
                logs[i].length = TRTLSHORT_L;
                logs[i].speed = TRTLSPD_S;
            }
            else if(i<LEVEL_4_SHORT_LOGS+LEVEL_4_LONG_LOGS+LEVEL_4_MEDIUM_LOGS+LEVEL_4_LONG_TURTLES+LEVEL_4_SHORT_TURTLES+LEVEL_4_DUCK) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = 0;//(i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES-1))*BUFFER_W/5;
                logs[i].length = DUCK_L;
                logs[i].speed = DUCKSPD;
            }
            logs[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_5:
        logs = (LOG*)malloc(LEVEL_5_LOGS*(sizeof(LOG)));
        for (int i = 0; i < LEVEL_5_LOGS; i++) {
            if (i<LEVEL_5_SHORT_LOGS) {
                logs[i].pos.lane = 6;
                logs[i].pos.x = i*(BUFFER_W/3);
                logs[i].length = SHORT_LOG_L;
                logs[i].speed = LOGSPD_S;
            }
            else if (i<LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS) {
                logs[i].pos.lane = 5;
                logs[i].pos.x = (BUFFER_W/2)*(i-(LEVEL_5_SHORT_LOGS-1));
                logs[i].length = LONG_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = (BUFFER_W/3)*(i-(LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS-1));
                logs[i].length = MEDIUM_LOG_L;
                logs[i].speed = LOGSPD_F;
            }
            else if (i<LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS+LEVEL_5_LONG_TURTLES) {
                logs[i].pos.lane = 7;
                logs[i].pos.x = (i-(LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS-1))*BUFFER_W/4;    
                logs[i].length = TRTLLONG_L;
                logs[i].speed = TRTLSPD_F;
            }
            else if (i<LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS+LEVEL_5_LONG_TURTLES+LEVEL_5_SHORT_TURTLES) {
                logs[i].pos.lane = 4;
                logs[i].pos.x = (i-(LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS+LEVEL_5_LONG_TURTLES-1))*BUFFER_W/4;
                logs[i].length = TRTLSHORT_L;
                logs[i].speed = TRTLSPD_S;
            }
            else if(i<LEVEL_5_SHORT_LOGS+LEVEL_5_LONG_LOGS+LEVEL_5_MEDIUM_LOGS+LEVEL_5_LONG_TURTLES+LEVEL_5_SHORT_TURTLES+LEVEL_5_DUCK) {
                logs[i].pos.lane = 3;
                logs[i].pos.x = 0;//(i-(LEVEL_3_SHORT_LOGS+LEVEL_3_LONG_LOGS+LEVEL_3_MEDIUM_LOGS+LEVEL_3_LONG_TURTLES+LEVEL_3_SHORT_TURTLES-1))*BUFFER_W/5;
                logs[i].length = DUCK_L;
                logs[i].speed = DUCKSPD;
            }
            logs[i].speed*=(1+j/3);
        }
        break;
            
    }
    
    return logs;
}

TURTLES* turtles_init(unsigned int level) {
    TURTLES* turtles;
    int j = 0;
    if (level>LEVEL_5) {
        while(level>5) {
            level -=5;
            j++;
        }
    }
    switch (level) {
    case LEVEL_1:
        turtles = (TURTLES*)malloc(LEVEL_1_DIVING_TURTLES*(sizeof(TURTLES)));
        for (int i = 0; i < LEVEL_1_DIVING_TURTLES; i++) {
            if (i<1) {
                turtles[i].pos.lane = 7;
                turtles[i].pos.x = (LEVEL_1_LONG_TURTLES)*BUFFER_W/4;
                turtles[i].length = TRTLLONG_L;
                turtles[i].speed = TRTLSPD_F;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
        
            else if (i<2) {
                turtles[i].pos.lane = 4;
                turtles[i].pos.x = (LEVEL_1_SHORT_TURTLES)*BUFFER_W/4;
                turtles[i].length = TRTLSHORT_L;
                turtles[i].speed = TRTLSPD_S;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
            turtles[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_2:   
        turtles = (TURTLES*)malloc(LEVEL_2_DIVING_TURTLES*(sizeof(TURTLES)));
        for (int i = 0; i < LEVEL_2_DIVING_TURTLES; i++) {
            if (i<1) {
                turtles[i].pos.lane = 7;
                turtles[i].pos.x = (LEVEL_2_LONG_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLLONG_L;
                turtles[i].speed = TRTLSPD_F;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
        
            else if (i<2) {
                turtles[i].pos.lane = 4;
                turtles[i].pos.x = (LEVEL_2_SHORT_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLSHORT_L;
                turtles[i].speed = TRTLSPD_S;
                turtles[i].divingstate = 3;
                turtles[i].timer = 100;
            }
            else if (i<3) {
                turtles[i].pos.lane = 3;
                turtles[i].pos.x = (BUFFER_W/3)*(LEVEL_2_MEDIUM_LOGS+1);
                turtles[i].length = CROC_L;
                turtles[i].speed = LOGSPD_F;
                turtles[i].divingstate = TURTLE_LOG;
                turtles[i].timer = 100;
            }
            turtles[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_3:   
        turtles = (TURTLES*)malloc(LEVEL_3_DIVING_TURTLES*(sizeof(TURTLES)));
        for (int i = 0; i < LEVEL_3_DIVING_TURTLES; i++) {
            if (i<1) {
                turtles[i].pos.lane = 7;
                turtles[i].pos.x = (LEVEL_3_LONG_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLLONG_L;
                turtles[i].speed = TRTLSPD_F;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
        
            else if (i<2) {
                turtles[i].pos.lane = 4;
                turtles[i].pos.x = (LEVEL_3_SHORT_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLSHORT_L;
                turtles[i].speed = TRTLSPD_S;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
            else if (i<3) {
                turtles[i].pos.lane = 3;
                turtles[i].pos.x = (BUFFER_W/3)*(LEVEL_2_MEDIUM_LOGS+1);
                turtles[i].length = CROC_L;
                turtles[i].speed = LOGSPD_F;
                turtles[i].divingstate = TURTLE_LOG;
                turtles[i].timer = 100;
            }
            turtles[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_4:   
        turtles = (TURTLES*)malloc(LEVEL_4_DIVING_TURTLES*(sizeof(TURTLES)));
        for (int i = 0; i < LEVEL_4_DIVING_TURTLES; i++) {
            if (i<1) {
                turtles[i].pos.lane = 7;
                turtles[i].pos.x = (LEVEL_4_LONG_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLLONG_L;
                turtles[i].speed = TRTLSPD_F;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
        
            else if (i<2) {
                turtles[i].pos.lane = 4;
                turtles[i].pos.x = (LEVEL_4_SHORT_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLSHORT_L;
                turtles[i].speed = TRTLSPD_S;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
            else if (i<3) {
                turtles[i].pos.lane = 3;
                turtles[i].pos.x = (BUFFER_W/3)*(LEVEL_2_MEDIUM_LOGS+1);
                turtles[i].length = CROC_L;
                turtles[i].speed = LOGSPD_F;
                turtles[i].divingstate = TURTLE_LOG;
                turtles[i].timer = 100;
            }
            turtles[i].speed*=(1+j/3);
        }
        break;
    case LEVEL_5:   
        turtles = (TURTLES*)malloc(LEVEL_5_DIVING_TURTLES*(sizeof(TURTLES)));
        for (int i = 0; i < LEVEL_5_DIVING_TURTLES; i++) {
            if (i<1) {
                turtles[i].pos.lane = 7;
                turtles[i].pos.x = (LEVEL_5_LONG_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLLONG_L;
                turtles[i].speed = TRTLSPD_F;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
        
            else if (i<2) {
                turtles[i].pos.lane = 4;
                turtles[i].pos.x = (LEVEL_5_SHORT_TURTLES+1)*BUFFER_W/4;
                turtles[i].length = TRTLSHORT_L;
                turtles[i].speed = TRTLSPD_S;
                turtles[i].divingstate = TURTLE_ABOVE_1;
                turtles[i].timer = 100;
            }
            else if (i<3) {
                turtles[i].pos.lane = 3;
                turtles[i].pos.x = (BUFFER_W/3)*(LEVEL_2_MEDIUM_LOGS+1);
                turtles[i].length = CROC_L;
                turtles[i].speed = LOGSPD_F;
                turtles[i].divingstate = TURTLE_LOG;
                turtles[i].timer = 100;
            }
            turtles[i].speed*=(1+j/3);
        }
        break;
    }
    return turtles;
}

