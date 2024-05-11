/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:12:51 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/02 16:47:24 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbr_size(unsigned long long n, int b_len)
{
	size_t	cnt;

	cnt = 0;
	while (n)
	{
		n /= b_len;
		cnt++;
	}
	return (cnt);
}

char	*ft_convert_base(unsigned long long n, char *base, \
		int b_len, t_format *fmt)
{
	char	*ret;
	size_t	n_size;

	if (!n && !fmt->pre && fmt->chk_pre)
		return (ft_strdup(""));
	if (!n)
		return (ft_strdup("0"));
	n_size = ft_nbr_size(n, b_len);
	if (!(ret = malloc(n_size + 1)))
		return (0);
	ret[n_size] = 0;
	while (n_size)
	{
		ret[--n_size] = base[n % b_len];
		n /= b_len;
	}
	return (ret);
}

void	ft_frees(int cnt, ...)
{
	va_list ap;

	va_start(ap, cnt);
	while (cnt)
	{
		free(va_arg(ap, void *));
		cnt--;
	}
	va_end(ap);
}
