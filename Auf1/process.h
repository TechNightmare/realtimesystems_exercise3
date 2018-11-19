#ifndef PROCESS_H
#define PROCESS_H

    #include <stdint.h>
    
    typedef enum state{READY, RUNNING, BLOCKED} state;

    struct process{
        uint32_t p_id;
        state p_state;
    };

    void p_switch_state(struct process *p);

    void p_block_state(struct process *p);
    
    void p_print(struct process *p);

#endif