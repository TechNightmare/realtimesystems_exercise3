#include <stdio.h>
#include "processmodel.h"
#include "process.h"
#include "queue.h"

void print(struct pctx *ctx){
    puts("\nKontext des aktuell laufenden Prozesses:");
    p_print(ctx->running);
    q_print(ctx->qready);
    q_print(ctx->qblocked);
    //puts("");
}

void step(struct pctx *ctx){
    //struct process *runP = ctx->running;
    if(ctx->running){
        p_switch_state(ctx->running);
        q_add(ctx->qready, ctx->running);
    }
    ctx->running = q_remove(ctx->qready);
    p_switch_state(ctx->running);
}