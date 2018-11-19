#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

    struct pctx{
        struct queue *qready;
        struct process *running;
        struct queue *qblocked;
    };

    void print(struct pctx *ctx);

    void step(struct pctx *ctx);

#endif