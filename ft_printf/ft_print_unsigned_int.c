/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:57:19 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:30:41 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_flag(unsigned long long n)
{
	if (n < 0)
		write(1, "-", 1);
}

static void	ft_print_width(unsigned long long n, int len, char c,
		t_format *fmt)
{
	int size;

	size = len > fmt->pre ? len : fmt->pre;
	if (n < 0)
		size += 1;
	while (fmt->width - size > 0)
	{
		write(1, &c, 1);
		size++;
	}
}

static void	ft_print_precision(char *str, int len, t_format *fmt)
{
	while (fmt->pre > len)
	{
		write(1, "0", 1);
		len++;
	}
	while (*str)
		write(1, str++, 1);
}

static void	ft_print_format(unsigned long long n, char *str, t_format *fmt)
{
	if (fmt->zero && !fmt->minus && !fmt->chk_pre)
	{
		ft_print_flag(n);
		ft_print_width(n, ft_strlen(str), '0', fmt);
		ft_print_precision(str, ft_strlen(str), fmt);
	}
	else if (!fmt->minus)
	{
		ft_print_width(n, ft_strlen(str), ' ', fmt);
		ft_print_flag(n);
		ft_print_precision(str, ft_strlen(str), fmt);
	}
	else
	{
		ft_print_flag(n);
		ft_print_precision(str, ft_strlen(str), fmt);
		ft_print_width(n, ft_strlen(str), ' ', fmt);
	}
}

int			ft_print_unsigned_integer(va_list ap, t_format *fmt)
{
	unsigned long long	num;
	int					cnt;
	int					nlen;
	char				*nstr;

	num = va_arg(ap, unsigned int);
	if (**fmt->ptr == 'u')
		nstr = ft_convert_base(num, "0123456789", 10, fmt);
	else if (**fmt->ptr == 'o')
		nstr = ft_convert_base(num, "01234567", 8, fmt);
	else
		nstr = ft_convert_base(num, **fmt->ptr == 'x' ? \
				"0123456789abcdef" : "0123456789ABCDEF", 16, fmt);
	(*fmt->ptr)++;
	nlen = ft_strlen(nstr);
	cnt = fmt->width > nlen ? fmt->width : nlen;
	cnt = fmt->pre > cnt ? fmt->pre : cnt;
	ft_print_format(num, nstr, fmt);
	ft_frees(2, nstr, fmt);
	return (cnt);
}
