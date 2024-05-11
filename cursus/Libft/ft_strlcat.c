/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:17:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/18 15:37:14 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size < dst_len)
		return (src_len + size);
	i = dst_len;
	while (src[i - dst_len] && i + 1 < size)
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = 0;
	return (src_len + dst_len);
}
