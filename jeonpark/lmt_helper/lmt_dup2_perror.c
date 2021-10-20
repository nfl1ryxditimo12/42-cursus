/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_dup2_perror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:21 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 15:41:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// dup2()
#include <stdio.h>	// perror()
#include "lmt_helper.h"
#include "constant.h"

int	lmt_dup2_perror(int new_fd, int old_fd)
{
	int	result;

	result = dup2(new_fd, old_fd);
	if (result == FD_NONE)
		perror("dup");
	return (result);
}
