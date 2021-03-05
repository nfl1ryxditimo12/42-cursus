#include<unistd.h>
#include<stdlib.h>

void	print_str(char *c);

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		//argv[1]의 값을 가지고 보드 초기화하고 
		//보드 초기화에 실패(condition의 에러가 있는경우 에러 출력)
	}
	else
		print_str("Input Error!");
	write(1, "\n", 1);
	return (0);
}
