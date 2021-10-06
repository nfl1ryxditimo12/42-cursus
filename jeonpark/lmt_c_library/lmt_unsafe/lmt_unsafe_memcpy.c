/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_memcpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:05:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 20:18:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lmt_unsafe.h"
#include "lmt_constant.h"

void	*lmt_unsafe_memcpy(void *p_write, const void *p_read, size_t size)
{
	while (size > 0)
	{
		*(t_byte *)p_write++ = *(const t_byte *)p_read++;
		--size;
	}
	return (p_write);
}
