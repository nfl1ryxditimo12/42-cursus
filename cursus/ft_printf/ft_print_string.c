/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:44:47 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 18:34:53 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(char c, int len, t_format *fmt)
{
	int width;

	width = fmt->width;
	if (!fmt->width)
		return ;
	else if (fmt->chk_pre && fmt->pre < len)
		while (width > fmt->pre)
		{
			write(1, &c, 1);
			width--;
		}
	else
		while (width > len)
		{
			write(1, &c, 1);
			width--;
		}
}

static void	ft_print_precision(char *str, int len, t_format *fmt)
{
	int pre;

	pre = fmt->pre;
	if (fmt->chk_pre && !fmt->pre)
		return ;
	else if (fmt->chk_pre && fmt->pre < len)
		while (pre && *str)
		{
			write(1, str++, 1);
			pre--;
		}
	else
		while (*str)
			write(1, str++, 1);
}

static void	ft_print_format(char *str, int len, t_format *fmt)
{
	if (!fmt->minus)
	{
		ft_print_width(' ', len, fmt);
		ft_print_precision(str, len, fmt);
	}
	else
	{
		ft_print_precision(str, len, fmt);
		ft_print_width(' ', len, fmt);
	}
}

int			ft_print_string(va_list ap, t_format *fmt)
{
	char	*str;
	char	*tmp;
	int		len;
	int		cnt;

	tmp = va_arg(ap, char *);
	str = ft_strdup(tmp ? tmp : "(null)");
	if (!tmp)
	{
		if (fmt->chk_pre && fmt->pre)
			len = 6;
		else if (!fmt->chk_pre)
			len = 6;
		else
			len = 0;
	}
	else
		len = ft_strlen(str);
	cnt = (fmt->chk_pre && fmt->pre < len) ? fmt->pre : len;
	cnt = fmt->width > cnt ? fmt->width : cnt;
	ft_print_format(str, len, fmt);
	(*fmt->ptr)++;
	ft_frees(2, str, fmt);
	return (cnt);
}
