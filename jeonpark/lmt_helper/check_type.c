/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/23 18:04:50 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_helper.h"
#include "constant.h"

int	is_type_control_operator(int type)
{
	return ((type & TYPE_CONTROL_OPERATOR) != 0);
}

int	is_type_redirection(int type)
{
	return ((type & TYPE_REDIRECTION) != 0);
}

int	is_type_open_parenthesis(int type)
{
	return ((type & TYPE_OPEN_PARENTHESIS) != 0);
}

int	is_type_close_parenthesis(int type)
{
	return ((type & TYPE_CLOSE_PARENTHESIS) != 0);
}

int	is_type_command(int type)
{
	return ((type & TYPE_COMMAND) != 0);
}
