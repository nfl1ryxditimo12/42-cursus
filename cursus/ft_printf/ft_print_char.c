/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:02:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 13:47:14 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(char s, t_format *fmt)
{
	int	size;

	size = 0;
	while (fmt->width > ++size)
		write(1, &s, 1);
}

static void	ft_print_format(char c, t_format *fmt)
{
	if (!fmt->minus)
	{
		ft_print_width(' ', fmt);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		ft_print_width(' ', fmt);
	}
}

int			ft_print_char(va_list ap, t_format *fmt)
{
	int		c;
	int		cnt;

	(*fmt->ptr)++;
	c = (char)va_arg(ap, int);
	cnt = 1;
	cnt = fmt->width > cnt ? fmt->width : cnt;
	ft_print_format(c, fmt);
	free(fmt);
	return (cnt);
}
