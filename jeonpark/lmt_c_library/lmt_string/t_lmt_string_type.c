/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_string_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:02:54 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/20 17:02:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_string.h"
#include "lmt_alloc.h"
#include "lmt_unsafe.h"

//	stdlib.h: free()

static t_lmt_string	*lmt_string_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_string)));
}

void	lmt_string_init(t_lmt_string *string, const char *value)
{
	if (value == NULL)
		value = "";
	string->value = lmt_unsafe_strdup(value);
	string->count = lmt_unsafe_strlen(value);
}

t_lmt_string	*lmt_string_new(const char *value)
{
	t_lmt_string	*string;

	string = lmt_string_alloc();
	lmt_string_init(string, value);
	return (string);
}

void	lmt_string_free(t_lmt_string *string)
{
	free(string->value);
	free(string);
}
