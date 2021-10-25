/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_close_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:24:32 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/23 14:26:21 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_helper.h"
#include "lmt_c_library.h"
#include "constant.h"

void	lmt_close_fd(int *fd)
{
	if (*fd != FD_NONE)
		lmt_close(*fd);
	*fd = FD_NONE;
}
