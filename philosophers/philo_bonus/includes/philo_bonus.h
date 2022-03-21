/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:15:26 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/21 18:42:19 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				eat_count;
	long long		check_last_meal;
	struct s_state	*state;
}	t_philo;

typedef struct s_state
{
	int			philo_cnt;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			die;
	long long	start_time;
	pthread_t	tid;
	sem_t		*forks;
	sem_t		*writing;
	sem_t		*check_all_ate;
	t_philo		*philo;
}	t_state;

/** monitor.c */
void		*check_ate_philosophers(void *state_void);
void		check_death_philosophers(t_state *state, t_philo *philo);
void		wait_philosophers(t_state *state);
void		end_philosophers(t_state *state);

/** init.c */
int			init_state(t_state *state, int ac, char **av);

/** util.c */
int			philo_error(char *err);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
void		print_philo(t_state *state, int id, char *str);

/** time.c */
long long	now_time(void);
void		usleep_eating(t_state *state);
void		usleep_sleeping(t_state *state);

/** philo.c */
void		*dining_philosophers(void *philo_void);
int			philosophers(t_state *state);

#endif