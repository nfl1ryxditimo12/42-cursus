/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_dup2_perror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:21 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 20:15:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// dup2()
#include <stdlib.h>	// exit()
#include "lmt_helper.h"
#include "constant.h"

int	lmt_dup2_perror(int new_fd, int old_fd)
{
	int	result;

	result = dup2(new_fd, old_fd);
	if (result == FD_NONE)
	{
		lmt_perror("dup2");
		exit(result);
	}
	return (result);
}
