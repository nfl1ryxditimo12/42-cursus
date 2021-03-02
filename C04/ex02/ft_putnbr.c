/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 01:16:33 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/02 01:21:09 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	itoa(int nb)
{
	char ch_nb;

	if (nb == 0)
		return ;
	itoa(nb / 10);
	if (nb > 0)
	{
		ch_nb = (nb % 10) + '0';
		write(1, &ch_nb, 1);
	}
	else if (nb < 0)
	{
		ch_nb = -(nb % 10) + '0';
		write(1, &ch_nb, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		write(1, "-", 1);
	else if (nb == 0)
		write(1, "0", 1);
	itoa(nb);
}
