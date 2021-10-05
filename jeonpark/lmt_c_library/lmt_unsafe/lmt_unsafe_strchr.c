/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strchr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:50:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 17:50:24 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lmt_unsafe.h"

char	*lmt_unsafe_strchr(char *string, char *word)
{
	char	*p_char;

	p_char = string;
	while (*p_char != '\0')
	{
		if (lmt_unsafe_string_starts(p_char, word))
			return (p_char);
		++p_char;
	}
	return (NULL);
}
