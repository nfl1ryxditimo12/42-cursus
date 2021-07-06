/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_get_exit_code_from_stat_loc.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:54:36 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 18:55:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_util.h"

int	lmt_get_exit_code_from_stat_loc(int stat_loc)
{
	return ((stat_loc >> 8) & 0x000000ff);
}
