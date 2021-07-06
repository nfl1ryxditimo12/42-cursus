#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
	if (opendir("/bin/ls"))
		printf("yes\n");
	else
		printf("no\n");
}
