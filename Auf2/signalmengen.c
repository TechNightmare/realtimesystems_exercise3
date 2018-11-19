#include "signalmengen.h"
#include <stdint.h>

int my_sigemptyset(my_sigset_t *set)
{
	if(set)
	{
		*set = *set & 0;			// alle Signale 0 setzen
		return 0;
	}
	else
		return -1;
}

int my_sigfillset(my_sigset_t *set)
{
	if(set)
	{
		*set = *set | 0xFFFFFFFF;	// alle Signale 1 setzen	
		return 0;
	}
	else
		return -1;
}

int my_sigaddset(my_sigset_t *set, int signum)
{
	uint32_t temp = 1;
	temp = temp << (signum - 1); 

	if(set)
	{
		*set = *set | temp;			// setzen des bestimmten Signals
		return 0;
	}
	else
		return -1;
}

int my_sigdelset(my_sigset_t *set, int signum)
{
	uint32_t temp = 1;
	temp = temp << (signum - 1); 

	if(set)
	{
		*set = *set & ~temp;			// loeschen des bestimmten Signals
		return 0;
	}
	else
		return -1;
}

int my_sigismember(my_sigset_t *set, int signum)
{
	uint32_t temp = 1;
	temp = temp << (signum - 1); 

	if(set)
	{
		if(temp == (*set & temp))	// nur wenn Signal = 1 ist, wird ismember = 1
			return 1;
		else return -1;
	}
	else
		return -1;
}

