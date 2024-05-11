/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:00:00 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/15 13:46:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define max_value(a, b) ((a < b) ? b : a)
#define ft_isdigit(c) (('1' <= (c) && (c) <= '9') ? 1 : 0)
#define digit "0123456789abcdef"

int chk_digit(char *str, int *cnt)
{
	int ret;

	ret = 0;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + *str - '0';
		*cnt += 1;
		str++;
	}
	return (ret);
}

int ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	ft_putstr(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int	print_format(int len, int pad)
{
	int cnt;

	cnt = 0;
	if (len > 0)
		while (cnt++ < len)
			write(1, &pad, 1);
	return (len);
}

int process(char **fmt, va_list ap)
{
	unsigned long long num;
	long long	tmp;
	int base;
	int	is_negative;
	int cnt;
	int minus;
	int zero;
	int width;
	int chk_pre;
	int pre;
	int len;
	int digit;
	int pad;
	char *ret;

	cnt = 0;
	pad = ' ';
	minus = **fmt == '-' ? 1 : 0;
	zero = **fmt == '0' ? 1 : 0;
	*fmt += minus + zero;
	digit = 0;
	width = ft_isdigit(**fmt) ? chk_digit(*fmt, &digit) : 0;
	*fmt += digit;
	chk_pre = **fmt == '.' ? 1 : 0;
	*fmt += chk_pre;
	digit = 0;
	pre = (ft_isdigit(**fmt) && chk_pre) ? chk_digit(*fmt, &digit) : 0;
	*fmt += digit;
	len = 0;
	if (**fmt == 's')
	{
		ret = va_arg(ap, char *);
		if (ret == NULL)
			ret = "(null)";
		len = (chk_pre && pre < len) ? pre : ft_strlen(ret);
		cnt += print_format(pad, width);
		cnt += ft_putstr(ret, len);
	}
	else
	{
		if (**fmt == 'd')
		{
			tmp = va_arg(ap, int);
			is_negative = tmp < 0 ? 1 : 0;
			num = is_negative ? (-tmp) : tmp;
			base = 10;
		}
		else
		{
			num = va_arg(ap, unsigned int);
			is_negative = 0;
			base = 16;
		}
		if (!num)
		{
			if (!chk_pre || !pre)
			{
				ret = "";
				len = 0;
			}
			else
			{
				ret = "0";
				len = 1;
			}
		}
		else
		{
			word = (char [21]){};
			len = 20;
			while (num)
			{
				ret[len--] = digit[num % base];
				num /= base;
			}
			ret = &ret[len + 1];
			len = 20 - len;
		}
		if (is_nagetive)
			width--;
		pre = max_value(0, pre - len);
		width = max_value(0, width - (len + pre));
		cnt += print_format(pad, width);
		if (is_negative)
			cnt += write(1, "-", 1);
		pad = '0';
		cnt += print_format(pad, pre);
		cnt += ft_putstr(ret, len);
	}
	*fmt++;
	return (cnt);
}

int ft_printf(char *fmt, ...)
{
	va_list ap;
	int		ret;

	va_start(ap, fmt);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ret += process(&fmt, ap);
		}
		else
			ret += write(1, fmt++, 1);
	}
	va_end(ap);
	return (ret);
}
/*
int main()
{
	int a, b;

	a = ft_printf("hello\n");
	b = printf("hello\n");
	printf("%d %d\n", a, b);
}*/
