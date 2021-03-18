/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:24:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 11:44:54 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

# define COND_ERR "Condition is not valid\n"
# define CANT_ALLOC "Memory allocation ERROR\n"
# define BOARD_ERR "Board is not valid\n"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_bufcpy(char *dest, char *src, int n);
char	*get_value(int fd);
int		ft_atoi(char *str, int i);
char	*make_condition(char *cond);
void	read_file(char *file);

void	first_location(void);
void	set_tab(void);
void	dp(void);

void	g_arr_free(void);
void	print_error(char *error);
int		board_check(void);
int		board_valid(void);

int		is_newline(char c);
int		wd_len(char *str);
void	ftt_strcpy(char *dest, char *from, char *to);
int		line_check(char *str);
char	**ft_split(char *str);

extern char	**g_board;
extern char	g_blank;
extern char	g_obstacle;
extern char	g_fill;
extern int	**g_int_board;
extern int	g_row_size;
extern int	g_col_size;
extern int	**g_tab;
extern int	g_max_row;
extern int	g_max_col;
extern int	g_max;

#endif
