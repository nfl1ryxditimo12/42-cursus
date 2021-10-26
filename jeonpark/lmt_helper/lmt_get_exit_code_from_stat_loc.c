/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_get_exit_code_from_stat_loc.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:34 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 11:09:02 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_helper.h"

int	lmt_get_exit_code_from_stat_loc(int stat_loc)
{
	return ((stat_loc >> 8) & 0x000000ff);
}
