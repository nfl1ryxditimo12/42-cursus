/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:09:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/23 20:09:16 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lmt_alloc.h"
#include "lmt_constant.h"

//	stdlib.h: malloc(), exit(), size_t, NULL

void	*lmt_alloc(size_t size)
{
	void	*p_address;

	p_address = malloc(size);
	if (p_address == NULL)
		exit(1);
	return (p_address);
}
