/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:53:08 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:27:51 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_process(char *input, va_list ap)
{
	int cnt;
	int ctmp;

	cnt = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if ((ctmp = ft_format_init(&input, ap)) == -1)
				return (-1);
			cnt += ctmp;
		}
		else
		{
			ft_putchar_fd(*input++, 1);
			cnt++;
		}
	}
	return (cnt);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, input);
	ret = ft_printf_process((char *)input, ap);
	va_end(ap);
	return (ret);
}
