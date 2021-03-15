/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:24:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/15 14:44:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

# define COND_ERR "Condition is not valid"
# define CANT_ALLOC "Memory allocation ERROR"
# define BOARD_ERR "Board is not valid"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* read.c */
char	*get_value(int fd, char *c, int *i);
int	check_condition(int fd);
void	fill_board(int fd);
void	read_file(char *file);

/* print.c */
void	print_error(char *error);

/* check.c */
int	board_check(void);

/* string.c */
char	*ft_strdup(char *str);

/* exception.c */
void	board_valid(void);

/* global variable */
extern char	**g_board;
extern char	g_blank;
extern char	g_obstacle;
extern char	g_fill;
extern int	g_row_size;
extern int	g_col_size;

#endif
