/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 01:21:29 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 14:56:19 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int check_minus;
	int number;

	check_minus = 1;
	number = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == 45)
			check_minus *= -1;
	while ('0' <= *str && *str <= '9')
	{
		number *= 10;
		number = number + check_minus * (*(str++) - '0');
	}
	return (number);
}
