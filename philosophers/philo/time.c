/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:44:35 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/16 21:44:55 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	usleep_eating(t_state *state)
{
	long long	eat_time;
	long long	start_eat_time;
	long long	now_eat_time;

	eat_time = (long long)state->time_to_eat;
	start_eat_time = now_time();
	while (!state->die)
	{
		now_eat_time = now_time();
		if (now_eat_time - start_eat_time >= eat_time)
			break ;
		usleep(10);
	}
}

void	usleep_sleeping(t_state *state)
{
	long long	sleep_time;
	long long	start_sleep_time;
	long long	now_sleep_time;

	sleep_time = (long long)state->time_to_sleep;
	start_sleep_time = now_time();
	while (!state->die)
	{
		now_sleep_time = now_time();
		if (now_sleep_time - start_sleep_time >= sleep_time)
			break ;
		usleep(10);
	}
}