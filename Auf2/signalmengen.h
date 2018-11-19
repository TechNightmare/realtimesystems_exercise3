#ifndef SIGNALMENGEN_H
#define SIGNALMENGEN_H

	#include <stdint.h>


	typedef uint32_t my_sigset_t; 	// leeres Sigset fuer 32 Signale

	int my_sigemptyset(my_sigset_t *set);
	int my_sigfillset(my_sigset_t *set);
	int my_sigaddset(my_sigset_t *set, int signum);
	int my_sigdelset(my_sigset_t *set, int signum);
	int my_sigismember(my_sigset_t *set, int signum);

#endif