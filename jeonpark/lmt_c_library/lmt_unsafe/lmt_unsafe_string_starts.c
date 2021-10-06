/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:26:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/19 17:15:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_unsafe.h"
#include "lmt_constant.h"

int	lmt_unsafe_string_starts(char *string, char *word)
{
	while (*word != '\0')
		if (*string++ != *word++)
			return (FALSE);
	return (TRUE);
}
