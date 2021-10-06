/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strrchr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:50:21 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 17:50:25 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lmt_unsafe.h"

char	*lmt_unsafe_strrchr(char *string, char *word)
{
	char	*p_char;

	p_char = string;
	while (*p_char != '\0')
		++p_char;
	while (string < p_char)
	{
		--p_char;
		if (lmt_unsafe_string_starts(p_char, word))
			return (p_char);
	}
	return (NULL);
}
