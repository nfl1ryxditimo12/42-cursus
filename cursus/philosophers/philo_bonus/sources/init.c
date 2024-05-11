/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:48:47 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/21 18:46:46 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_state(t_state *state, int ac)
{
	if (state->philo_cnt < 1 || state->time_to_die == -1 || \
		state->time_to_eat == -1 || state->time_to_sleep == -1 || \
		(ac == 6 && state->must_eat_cnt == -1))
		return (0);
	return (1);
}

int	init_semaphore(t_state *state)
{
	int	i;

	i = -1;
	sem_unlink("forks");
	state->forks = sem_open("forks", O_CREAT, 0644, state->philo_cnt);
	if (state->forks == SEM_FAILED)
		return (0);
	sem_unlink("writing");
	state->writing = sem_open("writing", O_CREAT, 0644, 1);
	if (state->writing == SEM_FAILED)
		return (0);
	sem_unlink("check_all_ate");
	state->check_all_ate = sem_open("check_all_ate", O_CREAT, 0644, \
													state->philo_cnt);
	if (state->check_all_ate == SEM_FAILED)
		return (0);
	while (++i < state->philo_cnt)
		sem_wait(state->check_all_ate);
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
	state->die = 0;
	state->start_time = now_time();
	if (!check_state(state, ac) || !init_semaphore(state) || !init_philo(state))
		return (0);
	return (1);
}
