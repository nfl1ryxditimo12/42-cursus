/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:31:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/08 11:43:22 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	char	*tmp;

	tmp = dst;
	if (!dst && !src)
		return (0);
	while (num--)
		*((unsigned char *)tmp++) = *((unsigned char *)src++);
	return (dst);
}
