/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:32:10 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/06 15:20:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_baselen;

int	atoi(char *str)
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
	number = base_to_num(number);
	return (number);
}
