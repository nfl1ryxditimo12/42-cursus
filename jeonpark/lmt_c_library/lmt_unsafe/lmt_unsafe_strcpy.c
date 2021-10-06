/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strcpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 20:13:31 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_unsafe.h"

void	*lmt_unsafe_strcpy(char *p_write, const char *p_read)
{
	while (*p_read != '\0')
		*p_write++ = *p_read++;
	return (p_write);
}
