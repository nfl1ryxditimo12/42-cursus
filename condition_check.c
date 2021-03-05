#include <stdlib.h>

#define N 4

int	ft_check_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	**ft_dimension_change(int **cond, int *temp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
		{
			cond[i][j] = *temp;
			temp++;
		}
	}
	return (cond);
}

int	**ft_char_to_num(char *argv, int *count, int **cond)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * (N * N + 1));
	while (*argv)
	{
		if (ft_check_space(*argv) == 1)
			argv++;
		else if ('1' <= *argv && *argv <= N + '0')
		{
			if (!ft_check_space(*(argv + 1)) && *(argv + 1) != '\0')
				return (0);
			*temp = *argv - '0';
			(*count)++;
			temp++;
			argv++;
		}
		else
			return (0);
	}
	temp -= *count;
	return (ft_dimension_change(cond, temp));
}

int	ft_check_coner(int **cond)
{
	if (cond[0][0] + cond[2][0] == 2 && cond[0][0] == cond[2][0])
		return (1);
	if (cond[0][3] + cond[3][0] == 2 && cond[0][3] == cond[3][0])
		return (1);
	if (cond[1][0] + cond[2][3] == 2 && cond[1][0] == cond[2][3])
		return (1);
	if (cond[1][3] + cond[3][3] == 2 && cond[1][3] == cond[3][3])
		return (1);
	return (1);
}

int	**ft_condition_check(char **argv)
{
	int	**cond;
	int	count;
	int	i;

	cond = (int **)malloc(sizeof(int *) * (N + 1));
	count = 0;
	i = -1;
	while (++i < N)
		cond[i] = (int *)malloc(sizeof(int) * (N + 1));
	cond = ft_char_to_num(argv[1], &count, cond);
	if (ft_check_coner(cond))
		if (count == 16)
			return (cond);
	return (0);
}
