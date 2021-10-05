/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_put_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/05 13:48:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "lmt_io.h"

void	lmt_put_ch(const char ch)
{
	ssize_t	return_value;

	return_value = write(1, &ch, 1);
	if (return_value == -1)
		exit(1);
}
