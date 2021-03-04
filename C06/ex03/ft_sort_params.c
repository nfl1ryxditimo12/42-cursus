/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:41:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/04 15:19:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *arr1, char *arr2)
{
	while (*arr1 && *arr2)
	{
		if (*arr1 != *arr2)
			return (*arr1 - *arr2);
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}

void	sort(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (++j < argc)
		{
			if (ft_strcmp(argv[j - 1], argv[j]) < 0)
			{
				tmp = argv[j - 1];
				argv[j - 1] = argv[j];
				argv[j] = tmp;
			}
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	sort(argc, argv);
	argc -= 1;
	while (argc > 0)
	{
		while (*argv[argc])
			write(1, argv[argc]++, 1);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
