/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_open_perror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:07:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 14:08:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// open(), mode_t
#include <stdio.h>	// perror()
#include "lmt_helper.h"

int	lmt_open_perror(const char *path, int oflag, mode_t mode)
{
	int	fd;

	if (mode == 0)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, mode);
	if (fd == -1)
		perror("open");
	return (fd);
}
