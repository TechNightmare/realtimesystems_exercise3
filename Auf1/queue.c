#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "process.h"

void q_add(struct queue *q, struct process *p){
    q_node *new_node;
    if(!q || !p){
        fprintf(stderr, "q_add: Keine Queue oder kein Prozess uebergeben!");
    }else if((new_node = calloc(1, sizeof(q_node)))){
        //puts("Stuff");
        if(q->start == NULL){
            //puts("Stuff");
            q->start = new_node;
            q->end = new_node;
            //puts("Stuff");
        } 
        else{
            q->end->next = new_node;
            q->end = new_node;
        }
        new_node->p = p;
        new_node->next = NULL;
    }else fprintf(stderr, "q_add: Speicherreservierung fehlgeschlagen!");
}

//!q ... ergibt das überhaupt einen Sinn???
struct process *q_remove(struct queue *q){
    if(q->start){
        q_node *node = q->start;
        struct process *ret_p = node->p;
        q->start = node->next;
        if(!q->start) q->end = NULL; //wenn start NULL ist, ist auch das Ende NULL
        free(node);
        //puts("stuff");
        return ret_p;
    }
    return NULL;
}

void q_print(struct queue *q){
    if(q->start){
        q_node *print = q->start;
        if(print->p->p_state == BLOCKED)
            puts("Blocked Processes:");
        else
            puts("Current Queue:");
        while(print){
            p_print(print->p);
            print = print->next;
            //puts("\n");
        }
    }else if(!q) fprintf(stderr, "q_print: Keine Queue uebergeben!");
}