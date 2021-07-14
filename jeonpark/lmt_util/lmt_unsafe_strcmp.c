/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_unsafe_strcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:35:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 13:20:24 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"

int	lmt_unsafe_strcmp(char *lhs, char *rhs)
{
	size_t	size;

	size = lmt_unsafe_strlen(lhs);
	return (lmt_unsafe_memcmp(lhs, rhs, size));
}
