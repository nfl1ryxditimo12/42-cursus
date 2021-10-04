/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_return_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:06:29 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/17 22:21:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "lmt_util.h"

int	lmt_return_error(int exit_status, char *string)
{
	printf("minishell: %s: %s\n", string, strerror(errno));
	return (exit_status);
}
