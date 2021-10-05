/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:00:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/01 13:11:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lmt_unsafe.h"

size_t	lmt_unsafe_strlen(const char *p_string)
{
	const char	*p_string_ch;

	p_string_ch = p_string;
	while (*p_string_ch != '\0')
		++p_string_ch;
	return (p_string_ch - p_string);
}
