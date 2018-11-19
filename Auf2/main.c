#include "signalmengen.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>



int main() {
	my_sigset_t set;

	my_sigemptyset(&set);
	printf("%d\n",my_sigismember(&set,SIGTERM));

	my_sigaddset(&set,SIGTERM);
	printf("%d\n",my_sigismember(&set,SIGTERM));

	my_sigdelset(&set,SIGTERM);
	printf("%d\n",my_sigismember(&set,SIGTERM));
	
	my_sigfillset(&set);
	printf("%d\n",my_sigismember(&set,SIGTERM));

	return EXIT_SUCCESS;
}