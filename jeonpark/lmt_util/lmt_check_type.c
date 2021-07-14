/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:33:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 13:21:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_check_type.h"
#include "lmt_util.h"

int	lmt_is_type_redirection(int type)
{
	return ((type & TYPE_REDIRECTION) != 0);
}

int	lmt_is_type_operator(int type)
{
	return ((type & TYPE_DELIMITER) != 0);
}

///	If string match one of builtin command, return 1 nor 0
int	lmt_is_builtin(char *string)
{
	if (string == NULL)
		return (0);
	if (lmt_unsafe_strcmp(string, "echo") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "cd") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "pwd") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "export") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "unset") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "env") == 0)
		return (1);
	if (lmt_unsafe_strcmp(string, "exit") == 0)
		return (1);
	return (0);
}
