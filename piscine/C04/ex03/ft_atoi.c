/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 01:21:29 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/09 21:06:04 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int check_minus;
	int number;

	check_minus = 1;
	number = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == 45)
			check_minus *= -1;
	while ('0' <= *str && *str <= '9')
		number = number * 10 + *(str++) - '0';
	return (number * check_minus);
}
