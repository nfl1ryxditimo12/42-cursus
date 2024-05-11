/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:08:00 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/10 20:08:11 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *src1, void *src2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)src1 == *(unsigned char *)src2)
		{
			src1++;
			src2++;
		}
		else
			return (*(unsigned char *)src1 - *(unsigned char *)src2);
	}
	return (0);
}
