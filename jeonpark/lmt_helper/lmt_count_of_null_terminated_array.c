/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_count_of_null_terminated_array.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:28:55 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:28:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "lmt_helper.h"

int	lmt_count_of_null_terminated_array(void **array)
{
	int	count;

	count = 0;
	while (*array != NULL)
	{
		++count;
		++array;
	}
	return (count);
}
