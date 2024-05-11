/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:25:47 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 17:32:13 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(char c, int len, t_format *fmt)
{
	while (fmt->width > len + 2)
	{
		write(1, &c, 1);
		len++;
	}
}

static void	ft_print_precision(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	ft_print_format(char *str, int len, t_format *fmt)
{
	if (fmt->zero && !fmt->minus && !fmt->pre)
	{
		write(1, "0x", 2);
		ft_print_width('0', len, fmt);
		ft_print_precision(str);
	}
	else if (!fmt->minus)
	{
		ft_print_width(' ', len, fmt);
		write(1, "0x", 2);
		ft_print_precision(str);
	}
	else
	{
		write(1, "0x", 2);
		ft_print_precision(str);
		ft_print_width(' ', len, fmt);
	}
}

int			ft_print_pointer(va_list ap, t_format *fmt)
{
	char		*str;
	long long	n;
	int			len;
	int			cnt;

	n = (long long)va_arg(ap, void *);
	str = ft_convert_base(n, "0123456789abcdef", 16, fmt);
	len = ft_strlen(str);
	cnt = fmt->width > len + 2 ? fmt->width : len + 2;
	cnt = fmt->pre + 2 > cnt ? fmt->pre + 2 : cnt;
	ft_print_format(str, len, fmt);
	(*fmt->ptr)++;
	ft_frees(2, str, fmt);
	return (cnt);
}
