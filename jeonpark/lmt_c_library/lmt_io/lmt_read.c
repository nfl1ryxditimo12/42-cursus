/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:32:40 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/05 13:48:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>
#include "lmt_io.h"

ssize_t	lmt_read(int fd, void *buffer, size_t size)
{
	ssize_t	reads_len;

	reads_len = read(fd, buffer, size);
	if (reads_len == -1)
		exit(1);
	return (reads_len);
}
