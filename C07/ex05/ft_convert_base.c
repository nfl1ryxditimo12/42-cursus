/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:09:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 18:58:53 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c);
int	is_valid(char *base);
int	nbr_size(int nbr, int base_len);

int	atoi_(char *nbr, char *base, int base_len)
{
	int	check;
	int	num;
	int	i;

	check = 1;
	num = 0;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == 43 || *nbr == 45)
		if (*(nbr++) == 45)
			check *= -1;
	while (*nbr)
	{
		i = -1;
		while (++i < base_len)
		{
			if (*nbr == base[i])
				break ;
		}
		if (i == base_len)
			break ;
		num = num * base_len + i;
		nbr++;
	}
	return (num * check);
}

char	*putnbr_(int nbr, char *base, int base_len)
{
	int	tmp;
	int	size;
	char	*ret;

	if (nbr == 0)
	{
		ret = (char *)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_size(nbr, base_len);
	ret = (char *)malloc(size + 1);
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	to_len;
	int	from_len;

	to_len = is_valid(base_to);
	from_len = is_valid(base_from);
	
	if (!to_len || !from_len)
		return (0);
	return (putnbr_(atoi_(nbr, base_from, from_len), base_to, to_len));
}
