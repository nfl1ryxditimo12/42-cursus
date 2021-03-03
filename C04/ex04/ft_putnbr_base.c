/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 01:27:02 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/03 16:53:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output(int nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	output(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

int	exception(char *base, int len)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	if (exception(base, i) == 0)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	else if (nbr > 0)
		output(nbr, base, i);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		output(-nbr, base, i);
	}
}
