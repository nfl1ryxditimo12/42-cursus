/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:02:39 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/16 21:50:07 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_ate_philosophers(t_state *state)
{
	int	i;

	i = 0;
	while (state->must_eat_cnt != -1 && i < state->philo_cnt && \
			state->philo[i].eat_count > state->must_eat_cnt)
		i++;
	if (i == state->philo_cnt)
		state->check_all_ate = 1;
	return ;
}

void	check_death_philosophers(t_state *state)
{
	int	i;

	while (!state->check_all_ate)
	{
		i = -1;
		while (++i < state->philo_cnt && !state->die)
		{
			pthread_mutex_lock(&state->eating);
			if (now_time() - state->philo[i].check_last_meal > \
													state->time_to_die)
				print_philo(state, state->philo[i].id, "is died");
			pthread_mutex_unlock(&state->eating);
		}
		if (state->die)
			break ;
		check_ate_philosophers(state);
	}
	return ;
}

int	check_state(t_state *state, int ac)
{
	if (state->philo_cnt < 1 || state->time_to_die == -1 || \
		state->time_to_eat == -1 || state->time_to_sleep == -1 || \
		(ac == 6 && state->must_eat_cnt == -1))
		return (0);
	return (1);
}
