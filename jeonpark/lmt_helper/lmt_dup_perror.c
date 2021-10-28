/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_dup_perror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:07:36 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 20:15:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// dup()
#include <stdlib.h>	// exit()
#include "lmt_helper.h"
#include "constant.h"

int	lmt_dup_perror(int old_fd)
{
	int	new_fd;

	new_fd = dup(old_fd);
	if (new_fd == FD_NONE)
	{
		lmt_perror("dup");
		exit(new_fd);
	}
	return (new_fd);
}
