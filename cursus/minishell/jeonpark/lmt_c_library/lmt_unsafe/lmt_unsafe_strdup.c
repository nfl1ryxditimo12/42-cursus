/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strdup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:13:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 14:13:49 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lmt_unsafe.h"
#include "lmt_alloc.h"

void	*lmt_unsafe_strdup(const char *string)
{
	size_t	count;
	char	*string_dup;

	count = lmt_unsafe_strlen(string) + 1;
	string_dup = lmt_alloc(sizeof(*string_dup) * count);
	lmt_unsafe_memcpy(string_dup, string, count);
	return (string_dup);
}
