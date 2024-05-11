/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:32:10 by seonkim           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/14 00:51:11 by seonkim          ###   ########.fr       */
=======
/*   Updated: 2021/03/14 15:03:03 by seonkim          ###   ########.fr       */
>>>>>>> 5a1bcf3de2bb113a5eb48ed378a3f1b87b1c33d7
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int g_baselen;

int	atoi(char *str, char *base, )
{
	int check_minus;
	int number;

	check_minus = 1;
	number = 0;
<<<<<<< HEAD
	while (*str == 32 || (9 <= *str && *str <= 13))
=======
	while (*str == 32 || (9 <= *str && *str <= 13)
>>>>>>> 5a1bcf3de2bb113a5eb48ed378a3f1b87b1c33d7
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == 45)
			check_minus *= -1;
	while ('0' <= *str && *str <= '9')
		number = number * 10 + *(str++) - '0';
	return (number * check_minus);
}

int	exception(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < g_baselen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_to_num(int num)
{
	if (num == 0)
		return (0);
	return ((num % g_baselen) + (base_to_num(num / g_baselen) * 10));
}

int	ft_atoi_base(char *str, char *base)
{
	int number;

	g_baselen = 0;
	while (base[g_baselen])
		g_baselen++;
	if (exception(base) == 0)
		return (0);
	number = atoi(str);
	return (base_to_num(number));
}

int main()
{
	printf("%d", ft_atoi_base("10", "01"));
}
