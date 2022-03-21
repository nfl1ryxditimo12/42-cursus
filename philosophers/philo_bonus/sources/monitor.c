/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:38:00 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/21 18:49:21 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philosophers(t_state *state)
{
	int	i;

	i = -1;
	while (++i < state->philo_cnt)
		kill(state->philo[i].pid, SIGKILL);
}

void	*check_ate_philosophers(void *state_void)
{
	t_state	*state;
	int		i;

	state = (t_state *)state_void;
	i = -1;
	while (++i < state->philo_cnt)
		sem_wait(state->check_all_ate);
	sem_wait(state->writing);
	kill_all_philosophers(state);
	sem_post(state->writing);
	return (NULL);
}

void	check_death_philosophers(t_state *state, t_philo *philo)
{
	int	i;

	i = -1;
	while (!state->die)
		if (now_time() - philo->check_last_meal > state->time_to_die)
			print_philo(state, state->philo[i].id, "is died");
}

void	wait_philosophers(t_state *state)
{
	int	i;
	int	status;

	i = -1;
	while (++i < state->philo_cnt)
	{
		waitpid(-1, &status, 0);
		if (status == 256)
		{
			kill_all_philosophers(state);
			return ;
		}
	}
}

void	end_philosophers(t_state *state)
{
	if (state->must_eat_cnt != -1)
		pthread_detach(state->tid);
	sem_close(state->forks);
	sem_close(state->writing);
	sem_close(state->check_all_ate);
	sem_unlink("forks");
	sem_unlink("writing");
	sem_unlink("check_all_ate");
	free(state->philo);
}

