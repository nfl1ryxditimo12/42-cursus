/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:53:14 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/22 17:08:32 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	itoa_hex(char nb)
{
	int		dex;
	char	ch_nb;

	dex = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	itoa_HEX(dex / 16);
	if (dex % 16 > 9)
	{
		ch_nb = (dex % 16) + 87;
		write(1, &ch_nb, 1);
	}
	else if (dex % 16 <= 9)
	{
		ch_nb = (dex % 16) + '0';
		write(1, &ch_nb, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 127)
		{
			write(1, "\\", 1);
			itoa_HEX(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
