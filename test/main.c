#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	struct stat st;
	int ret;

	ret = stat("/bin/ls", &st);
	printf("%ld\n", st.st_atime);

	printf("%d\n", ret);
}
