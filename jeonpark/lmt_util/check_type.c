/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 05:59:05 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"
#include "constant.h"

int	is_type_operator(int type)
{
	return ((type & TYPE_OPERATOR) != 0);
}

int	is_type_redirection(int type)
{
	return ((type & TYPE_REDIRECTION) != 0);
}
