/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:01:53 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 17:04:27 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_flag(va_list ap, t_format *fmt)
{
	if (**fmt->ptr == '-')
		fmt->minus = 1;
	else if (**fmt->ptr == '0')
		fmt->zero = 1;
	(*fmt->ptr)++;
	return (ft_format_process(ap, fmt));
}

int	ft_format_width(va_list ap, t_format *fmt)
{
	if (**fmt->ptr == '*')
	{
		fmt->width = va_arg(ap, int);
		(*fmt->ptr)++;
	}
	else
		while (ft_isdigit(**fmt->ptr))
			fmt->width = fmt->width * 10 + *(*fmt->ptr)++ - '0';
	if (fmt->width < 0)
	{
		fmt->minus = 1;
		fmt->width *= -1;
	}
	return (ft_format_process(ap, fmt));
}

int	ft_format_precision(va_list ap, t_format *fmt)
{
	(*fmt->ptr)++;
	fmt->chk_pre = 1;
	if (**fmt->ptr == '*')
	{
		if ((fmt->pre = va_arg(ap, int)) < 0)
			fmt->chk_pre = 0;
		(*fmt->ptr)++;
	}
	else
		while (ft_isdigit(**fmt->ptr))
			fmt->pre = fmt->pre * 10 + *(*fmt->ptr)++ - '0';
	return (ft_format_process(ap, fmt));
}

int	ft_format_type(va_list ap, t_format *fmt)
{
	if (**fmt->ptr == 'd' || **fmt->ptr == 'i')
		return (ft_print_integer(ap, fmt));
	if (**fmt->ptr == 'u' || **fmt->ptr == 'o' || \
			**fmt->ptr == 'x' || **fmt->ptr == 'X')
		return (ft_print_unsigned_integer(ap, fmt));
	if (**fmt->ptr == 'c')
		return (ft_print_char(ap, fmt));
	if (**fmt->ptr == 's')
		return (ft_print_string(ap, fmt));
	if (**fmt->ptr == 'p')
		return (ft_print_pointer(ap, fmt));
	if (**fmt->ptr == '%')
		return (ft_print_percent(fmt));
	free(fmt);
	return (0);
}
