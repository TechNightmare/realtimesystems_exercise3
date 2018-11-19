#include <stdio.h>
//#include <stdlib.h>
#include "process.h"

void p_switch_state(struct process *p){
    if(p){
        if(p->p_state == READY) p->p_state = RUNNING;
        else p->p_state = READY;
    } 
}

void p_block_state(struct process *p){
    if(p){
        if(p->p_state == RUNNING) p->p_state = BLOCKED;
        else p->p_state = READY;
    }
}

void p_print(struct process *p){
    if(p){
        printf("Prozess-ID: %i ", p->p_id);
        switch(p->p_state){
            case READY:     printf("Prozess-Status: READY\n");
                            break;
            case RUNNING:   printf("Prozess-Status: RUNNING\n");
                            break;
            case BLOCKED:   printf("Prozess-Status: BLOCKED\n");
                            break;
        }
    }
    //if(p->p_state == READY) printf("Prozess-Status: READY\n");
    //else printf("Prozess-Status: RUNNING\n");
};
