/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:08:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/11 13:25:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int		main(int argc, int **argv)
{
	int fd;
	int rd;

	fd = 0;
	rd = 0;
	if (argc == 1)
		ft_putstr("File name missing.");
	else if (argc > 2)
		ft_putstr("Too many arguments.");
	else
	{
		fd = open(argv[1], O_READONLY);
		if (ft < 0)
			ft_putstr("Cannot read file.");
		else
		{
			while (
		}
		close(fd);
	}
	return (0);
}
