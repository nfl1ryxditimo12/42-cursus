/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:49:14 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 17:52:07 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(char c, t_format *fmt)
{
	int size;

	size = 0;
	while (fmt->width > ++size)
		write(1, &c, 1);
}

static void	ft_print_format(t_format *fmt)
{
	if (fmt->zero && !fmt->minus)
	{
		ft_print_width('0', fmt);
		write(1, "%", 1);
	}
	else if (!fmt->minus)
	{
		ft_print_width(' ', fmt);
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		ft_print_width(' ', fmt);
	}
}

int			ft_print_percent(t_format *fmt)
{
	int cnt;

	(*fmt->ptr)++;
	cnt = fmt->width > 1 ? fmt->width : 1;
	ft_print_format(fmt);
	free(fmt);
	return (cnt);
}
