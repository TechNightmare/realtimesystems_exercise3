#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "processmodel_demo.h"
#include "process.h"
#include "queue.h"
#include "processmodel.h"

#define ANZ 10

struct queue qblocked;
struct queue q;
struct pctx ctx;

void sigusr1_handler(){
    signal(SIGUSR1, sigusr1_handler);

    p_block_state(ctx.running);
    q_add(ctx.qblocked, ctx.running);
    //q_print(&qblocked);

    ctx.running = q_remove(ctx.qready);
    p_switch_state(ctx.running);
}

void sigusr2_handler(){
    signal(SIGUSR2, sigusr2_handler);

    if(ctx.qblocked->start){
        p_block_state(ctx.qblocked->start->p);
        puts("stuff");
        q_add(ctx.qready, q_remove(ctx.qblocked));
    }
}


/*
TO-DO

sigaction anstelle von signal() nutzen
*/


int main(){
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    //struct queue q;
    q.start = NULL;
    q.end = NULL;
    //struct pctx ctx;
    qblocked.end = NULL;
    qblocked.start = NULL;
    for(int i = 0; i < ANZ; i++) make_Queue(&q);
    
    ctx.qready = &q;
    ctx.qblocked = &qblocked;
    ctx.running = NULL;
    
    for(;;){
        step(&ctx);
        print(&ctx);
        sleep(1);
    }

}

void make_Queue(struct queue *q){
    struct process *p;
    if(!(p = calloc(1,sizeof(struct process))))
        fprintf(stderr, "Speicherreservierung fehlgeschlagen!\n");
    p->p_id = rand() % (1001);
    p->p_state = READY;
    
    q_add(q, p);
}