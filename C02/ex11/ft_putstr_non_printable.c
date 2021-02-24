/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:53:14 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 02:06:27 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    hex_to_char(char str)
{
	int hex1;
	int hex2;

	hex1 = (str / 16) + '0';
	hex2 = str % 16;
	write(1, &hex1, 1);
	if (str > 9)
		hex2 += 87;
	else if (str <= 9)
		hex2 += '0';
	write(1, &hex2, 1);
}

void    ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32)
		{
			write(1, "\\", 1);
			hex_to_char(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
