/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:43:33 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/15 14:47:45 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	**g_board;
int	g_row_size;
int	g_col_size;
char	g_blank;
char	g_obstacle;
char	g_fill;

char	*get_value(int fd, char *c, int *i)
{
	char	*str;

	if (!(str = malloc(128)))
		exit(1);
	while (c[0] != '\n')
	{
		str[*i] = c[0];
		read(fd, c, 1);
		(*i)++;
	}
	if (c[0] == '\n')
		read(fd, c, 1);
	return (str);
}

int	check_condition(int fd)
{
	char	*cond;
	char	*tmp;
	char	c[1];
	int	i;
	int	j;

	i = -1;
	j = -1;
	tmp = get_value(fd, c, &i);
	cond = ft_strdup(tmp);
	free(tmp);
	g_fill = cond[i - 1];
	g_obstacle = cond[i - 2];
	g_blank = cond[i - 3];
	g_row_size = 0;
	while (++j < i - 1)
		if ('0' <= cond[j] && cond[j] <= '9')
			g_row_size = g_row_size * 10 + cond[j] - '0';
		else
			return (0);
	free(cond);
	return (1);
}

void	fill_board(int fd)
{
	char	*tmp;
	char	c[1];
	int	len;
	int	i;

	// exception
	if (!(g_board = (char **)malloc(sizeof(char *) * (g_row_size + 1))))
		return ;
	i = -1;
	while (++i < g_row_size)
	{
		len = -1;
		tmp = get_value(fd, c, &len);
		g_col_size = len;
		g_board[i] = ft_strdup(tmp);
		free(tmp);
	}
	board_check();
}

void	read_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Can not open file");
	check_condition(fd);
	fill_board(fd);
	board_valid();
	close(fd);
}
