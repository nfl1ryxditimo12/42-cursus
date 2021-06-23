/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:26:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/11 15:45:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_digit(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt += 1;
	if (n == 0)
		cnt = 1;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;

	size = check_digit(n);
	if (!(ret = (char *)malloc(size + 1)))
		return (0);
	ret[size] = 0;
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	while (--size >= 0)
	{
		if (n > 0)
			ret[size] = n % 10 + 48;
		else if (n < 0)
			ret[size] = -(n % 10) + 48;
		n /= 10;
	}
	return (ret);
}
