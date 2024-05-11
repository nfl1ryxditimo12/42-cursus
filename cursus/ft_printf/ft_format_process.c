/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:00:57 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:26:58 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_format_reset(char **input)
{
	t_format *ret;

	if (!(ret = malloc(sizeof(t_format))))
		return (0);
	ret->minus = 0;
	ret->zero = 0;
	ret->width = 0;
	ret->pre = 0;
	ret->chk_pre = 0;
	ret->ptr = input;
	return (ret);
}

int			ft_format_process(va_list ap, t_format *fmt)
{
	char **format;

	format = fmt->ptr;
	if (!**format)
	{
		free(fmt);
		return (0);
	}
	if (ft_strchr("-0", **format))
		return (ft_format_flag(ap, fmt));
	if (ft_strchr("123456789*", **format))
		return (ft_format_width(ap, fmt));
	if (ft_strchr(".", **format))
		return (ft_format_precision(ap, fmt));
	if (ft_strchr("cspdiuoxX%", **format))
		return (ft_format_type(ap, fmt));
	free(fmt);
	return (0);
}

int			ft_format_init(char **input, va_list ap)
{
	t_format	*fmt;

	if (!(fmt = ft_format_reset(input)))
		return (-1);
	return (ft_format_process(ap, fmt));
}
