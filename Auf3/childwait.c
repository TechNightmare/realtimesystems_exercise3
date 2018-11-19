#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define CHILD 0

int children = 0;
//sigset_t set;

void sigchld_handler(){
    
    int ret;
    int pid = wait(&ret);
    
    children--;

    printf("Child: %d terminated (n = %d)\n", pid, children);
}

void usage(){
    printf("Usage:\n./childwait [Number of Children]\n");
}

int main(int argc, char const *argv[]){
    
    sigset_t set;
    sigfillset(&set);
    struct sigaction st;
    memset(&st,0,sizeof(struct sigaction));
    st.sa_handler = &sigchld_handler;
    st.sa_mask = set;

    sigaction(SIGCHLD, &st, NULL);

    if(argc != 2) usage();
    else{
        int p;

        for(int i = 0; i < atoi(argv[1]); i++){
            p = fork();
            if(p == CHILD){
                sleep(1+i);
                exit(0);
            }else{
                children++;
                printf("Child: %d started (n = %d)\n", p, children);
            } 
        }
        while(children > 0){
            sleep(2);
            printf("Parent: %d sleep(2)\n", getpid());
        }
    }
    printf("Parent: %d terminated\n", getpid());
    return 0;
}
