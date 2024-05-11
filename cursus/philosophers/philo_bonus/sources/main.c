/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:15:21 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/21 16:15:23 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_state			state;

	if ((ac != 5 && ac != 6) || !init_state(&state, ac, av))
		return (philo_error("Argument Error!!"));
	if (!philosophers(&state))
		return (philo_error("Philosophers Error!!"));
	return (0);
}
