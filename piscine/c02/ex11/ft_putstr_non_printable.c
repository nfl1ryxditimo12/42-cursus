/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongsu <seongsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:53:14 by seonkim           #+#    #+#             */
/*   Updated: 2021/02/24 15:02:55 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_to_char(char str)
{
	int hex1;
	int hex2;

	str += 4;
	hex1 = (str / 16);
	hex2 = str % 16;
	if (hex1 > 9)
		hex1 += 87;
	else if (hex1 <= 9)
		hex1 += '0';
	write(1, &hex1, 1);
	if (hex2 > 9)
		hex2 += 87;
	else if (hex2 <= 9)
		hex2 += '0';
	write(1, &hex2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

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
