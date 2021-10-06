/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:19:28 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/05 13:57:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_primitive_type.h"
#include "lmt_alloc.h"
#include "lmt_constant.h"

static unsigned long	lmt_ltoa_devide_10(unsigned long *p_number)
{
	*p_number /= 10;
	return (*p_number);
}

char					*lmt_ltoa(long number)
{
	unsigned long	positive_number;
	char			buffer[MAX_LONG_LENGTH];
	char			*p_buffer;
	char			*string;
	char			*p_string;

	positive_number = ((number >= 0) * 2 - 1) * number;
	p_buffer = buffer;
	*p_buffer++ = '0' + (positive_number % 10);
	while (lmt_ltoa_devide_10(&positive_number) != 0)
		*p_buffer++ = '0' + (positive_number % 10);
	string = lmt_alloc((number < 0) + (p_buffer - buffer) + 1);
	p_string = string;
	if (number < 0)
		*p_string++ = '-';
	while (p_buffer != buffer)
		*p_string++ = *(--p_buffer);
	*p_string = '\0';
	return (string);
}
