#include <unistd.h>	// pid_t, fork()
#include <stdlib.h>	// exit()
#include "constant.h"	// ERROR

pid_t	lmt_fork_exit()
{
	pid_t	result;

	result = fork();
	if (result == -1)
		exit(ERROR);
	return (result);
}
