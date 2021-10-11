/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:09:00 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 16:15:01 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_primitive_type.h"
#include "lmt_constant.h"

///	- parameters:
///		- lhs: non-optional
///		- rhs: non-optional
int	lmt_str_equals(const char *lhs, const char *rhs)
{
	while (*rhs != '\0')
		if (*lhs++ != *rhs++)
			return (FALSE);
	if (*lhs != '\0')
		return (FALSE);
	return (TRUE);
}
