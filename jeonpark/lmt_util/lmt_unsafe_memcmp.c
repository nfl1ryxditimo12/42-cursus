/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_memcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:27:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 13:03:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"

int	lmt_unsafe_memcmp(char *lhs, char *rhs, size_t size)
{
	while (size-- > 1)
	{
		if (*lhs != *rhs)
			return (lhs - rhs);
		++lhs;
		++rhs;
	}
	return (lhs - rhs);
}
