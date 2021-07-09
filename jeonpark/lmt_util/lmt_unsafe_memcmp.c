/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:27:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/09 17:30:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"

int	lmt_unsafe_memcmp(char *lhs, char *rhs, size_t size)
{
	while (size-- > 1)
		if (*lhs++ != *rhs++)
			break ;
	return (lhs - rhs);
}
