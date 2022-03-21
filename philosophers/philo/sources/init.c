/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:02:05 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/16 20:47:18 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_state *state)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&state->eating, NULL))
		return (0);
	if (pthread_mutex_init(&state->writing, NULL))
		return (0);
	state->forks = malloc(sizeof(pthread_mutex_t) * state->philo_cnt);
	if (!state->forks)
		return (0);
	while (++i < state->philo_cnt)
		if (pthread_mutex_init(&(state->forks[i]), NULL))
			return (0);
	return (1);
}

int	init_philo(t_state *state)
{
	int	i;

	i = -1;
	state->philo = malloc(sizeof(t_state) * state->philo_cnt);
	if (!state->philo)
		return (0);
	while (++i < state->philo_cnt)
	{
		state->philo[i].id = i;
		state->philo[i].left_fork = i;
		state->philo[i].right_fork = (i + 1) % state->philo_cnt;
		state->philo[i].eat_count = 0;
		state->philo[i].state = state;
	}
	return (1);
}

int	init_state(t_state *state, int ac, char **av)
{
	if (ac == 5)
		av[5] = NULL;
	state->philo_cnt = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	state->must_eat_cnt = ft_atoi(av[5]);
	state->check_all_ate = 0;
	state->die = 0;
	state->start_time = now_time();
	if (!check_state(state, ac) || !init_philo(state) || !init_mutex(state))
		return (0);
	return (1);
}
