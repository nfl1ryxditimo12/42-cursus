/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:16:45 by seonkim           #+#    #+#             */
/*   Updated: 2021/11/16 19:47:59 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error(char *err)
{
	printf("%s\n", err);
	return (1);
}

int	ft_atoi(char *str)
{
	long long	num;
	int			flag;

	num = 0;
	flag = 0;
	if (!str || !*str)
		return (-1);
	while (*str && (48 <= *str && *str <= 57))
		num = num * 10 + *(str++) - 48;
	if (*str || num > 2147483647 || num == 0)
		return (-1);
	return (num);
}

int	set_philo_state(t_state *state, int ac, char **av)
{
	av++;
	state->people = ft_atoi(av[0]);
	state->die = ft_atoi(av[1]);
	state->eat = ft_atoi(av[2]);
	state->sleep = ft_atoi(av[3]);
	state->count = ft_atoi(av[4]);
	if ((ac != 5 && ac != 6) || \
		state->people == -1 || state->die == -1 || \
		state->eat == -1 || state->sleep == -1)
		return (0);
	return (1);
}

void	dining_philosophers(t_state *state)
{
	return ;
}

int	main(int ac, char **av)
{
	t_state	state;

	if (!set_philo_state(&state, ac, av))
		return (philo_error("Argument Error"));
	dining_philosophers(&state);
	return (0);
}
