/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:23:59 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/17 00:14:54 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

void	ft_putstr(char *str);
void	ft_itoa(int value);
void	ft_putnbr(int value);
int		ft_atoi(char *str);

int		sum(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

void	init(void);
int		is_valid_operator(char op);

extern int	g_idx[50];
extern int	(*g_fp[5])(int, int);
extern char	*g_err[2];

#endif
