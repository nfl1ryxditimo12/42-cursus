/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:44 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/16 23:48:31 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_itoa(int value)
{
	char ch_v;

	if (value == 0)
		return ;
	ft_itoa(value / 10);
	ch_v = '0' + value % 10;
	write(1, &ch_v, 1);
}

void	ft_putnbr(int value)
{
	char ch_v;

	if (value < 0)
	{
		write(1, "-", 1);
		ft_itoa(-(value / 10));
		ch_v = '0' - value % 10;
	}
	else
	{
		ft_itoa(value / 10);
		ch_v = '0' + value % 10;
	}
	write(1, &ch_v, 1);
}

int		ft_atoi(char *str)
{
	int check;
	int num;

	check = 1;
	num = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	while (*str == 43 || *str == 45)
		if (*(str++) == 45)
			check *= -1;
	while (48 <= *str && *str <= 57)
		num = num * 10 + *(str++) - 48;
	return (num * check);
}
