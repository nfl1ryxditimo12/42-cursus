/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_get_number_of_signal_that_caused_term          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:37:01 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 17:37:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_helper.h"

int	lmt_get_number_of_signal_that_caused_termination(int stat_loc)
{
	return (stat_loc & 0177);
}
