/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_fork_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:28:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:30:24 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// pid_t, fork()
#include <stdlib.h>	// exit()
#include "constant.h"	// ERROR

pid_t	lmt_fork_exit(void)
{
	pid_t	result;

	result = fork();
	if (result == -1)
		exit(ERROR);
	return (result);
}
