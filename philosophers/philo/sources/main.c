/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:16:45 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/16 21:45:32 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_state			state;

	if ((ac != 5 && ac != 6) || !init_state(&state, ac, av))
		return (philo_error("Argument Error!!"));
	if (!philosophers(&state))
		return (philo_error("Philosophers Error!!"));
	return (0);
}
