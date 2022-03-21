/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:24:56 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/16 21:44:46 by seonkim          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

void	print_philo(t_state *state, int id, char *str)
{
	pthread_mutex_lock(&state->writing);
	if (!state->die)
		printf("%lld %d %s\n", now_time() - state->start_time, id + 1, str);
	if (ft_strcmp(str, "is died"))
		state->die = 1;
	pthread_mutex_unlock(&state->writing);
	return ;
}
