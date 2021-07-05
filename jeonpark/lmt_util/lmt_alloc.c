/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:23:29 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 11:11:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_util.h"

void	*lmt_alloc(size_t size)
{
	void	*p_address;

	p_address = malloc(size);
	if (p_address == NULL)
		lmt_exit(0 /* set ALLOCATION_ERROR */, "");
	return (p_address);
}
