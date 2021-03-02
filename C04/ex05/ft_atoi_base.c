/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:19:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/02 17:05:18 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	atoi(char *str)
{
	int check_minus;
	int number;

	check_minus = 1;
	number = 0;
	while (!('0' <= *str && *str <= '9'))
	{
		if (*str == 45)
			check_minus *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		number *= 10;
		number = number + check_minus * (*str - '0');
		str++;
	}
	return (number);
}

int	

int	exception(char *base, int len)
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
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int num;
	int i;

	num = atoi(str);
	i = 0;
	while (base[i])
		i++;
	if (exception(base, i) == 0)
		return (0);

	return (num);
}

int main()
{
	printf("%d", ft_atoi_base("42", "poneyvif"));
}
