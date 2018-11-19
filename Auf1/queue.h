#ifndef QUEUE_H
#define QUEUE_H

    typedef struct q_node{
        struct q_node *next;
        struct process *p;
    } q_node;

    struct queue{
        q_node *start;
        q_node *end;
    };
 
    void q_add(struct queue *q, struct process *p);

    struct process *q_remove(struct queue *q);

    void q_print(struct queue *q);
#endif