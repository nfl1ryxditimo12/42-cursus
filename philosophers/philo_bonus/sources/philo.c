/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:30:24 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/21 18:47:58 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating_philosophers(t_state *state, t_philo *philo)
{
	sem_wait(state->forks);
	sem_wait(state->forks);
	print_philo(state, philo->id, "has taken a forks");
	print_philo(state, philo->id, "is eating");
	philo->check_last_meal = now_time();
	philo->eat_count++;
	usleep_eating(state);
	if (philo->eat_count == state->must_eat_cnt)
		sem_post(state->check_all_ate);
	sem_post(state->forks);
	sem_post(state->forks);
}

void	*dining_philosophers(void *philo_void)
{
	t_philo	*philo;
	t_state	*state;

	philo = (t_philo *)philo_void;
	state = philo->state;
	if (philo->id % 2)
		usleep(1000);
	while (!state->die)
	{
		eating_philosophers(state, philo);
		if (philo->eat_count == state->must_eat_cnt)
			break ;
		print_philo(state, philo->id, "is sleeping");
		usleep_sleeping(state);
		print_philo(state, philo->id, "is thinking");
	}
	return (0);
}

int	philosophers(t_state *state)
{
	int		i;
	void	*philo_void;

	i = -1;
	if (state->must_eat_cnt != -1 && pthread_create(&state->tid, NULL, \
									check_ate_philosophers, (void *)state))
		return (0);
	while (++i < state->philo_cnt)
	{
		state->philo[i].check_last_meal = now_time();
		state->philo[i].pid = fork();
		if (state->philo[i].pid == 0)
		{
			philo_void = (void *)&(state->philo[i]);
			if (pthread_create(&state->tid, NULL, \
				dining_philosophers, philo_void))
				return (0);
			check_death_philosophers(state, &state->philo[i]);
			exit(0);
		}
	}
	wait_philosophers(state);
	end_philosophers(state);
	return (1);
}
