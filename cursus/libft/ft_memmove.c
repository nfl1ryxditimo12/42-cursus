/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:50:15 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/16 19:28:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	if (!dst && !src)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, num));
	while (num--)
		*((unsigned char *)dst + num) = *((unsigned char *)src + num);
	return (dst);
}
