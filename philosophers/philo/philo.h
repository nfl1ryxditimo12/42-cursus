/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:17:02 by seonkim           #+#    #+#             */
/*   Updated: 2022/03/20 21:13:20 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		check_last_meal;
	int				eat_count;
	pthread_t		tid;
	struct s_state	*state;
}	t_philo;

typedef struct s_state
{
	int				philo_cnt;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	int				check_all_ate;
	int				die;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	writing;
	t_philo			*philo;
}	t_state;

/** init.c */
int			init_state(t_state *state, int ac, char **av);
int			init_mutex(t_state *state);
int			init_philo(t_state *state);

/** check.c */
void		check_ate_philosophers(t_state *state);
void		check_death_philosophers(t_state *state);
int			check_state(t_state *state, int ac);

/** philo.c */
void		eating_time(t_state *state, t_philo *philo);
void		*dining_philosophers(void *philo_void);
int			end_philosophers(t_state *state, int count);
int			eating_philosophers(t_state *state, t_philo *philo);
int			philosophers(t_state *state);

/** time.c */
long long	now_time(void);
void		usleep_eating(t_state *state);
void		usleep_sleeping(t_state *state);

/** util.c */
int			philo_error(char *err);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
void		print_philo(t_state *state, int id, char *str);

#endif