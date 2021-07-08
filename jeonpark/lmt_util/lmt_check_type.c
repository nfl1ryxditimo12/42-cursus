/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:33:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 11:40:36 by jeonpark         ###   ########.fr       */
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
