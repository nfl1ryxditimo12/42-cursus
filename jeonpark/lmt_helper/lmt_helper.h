/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 17:37:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_HELPER_H
# define LMT_HELPER_H

# include <fcntl.h>	// mode_t
# include <unistd.h>	// pid_t
# include "minishell.h"

int		is_type_control_operator(int type);
int		is_type_redirection(int type);
int		is_type_open_parenthesis(int type);
int		is_type_close_parenthesis(int type);
int		is_type_command(int type);

void	lmt_close_fd(int *fd);

int		lmt_count_of_null_terminated_array(void **array);

void    lmt_convert_list(t_handler *handler);

void	lmt_critical_exit();

int		lmt_dup_perror(int old_fd);
int		lmt_dup2_perror(int new_fd, int old_fd);

pid_t	lmt_fork_exit();

int		lmt_get_exit_code_from_stat_loc(int stat_loc);

int		lmt_get_number_of_signal_that_caused_termination(int stat_loc);

int		lmt_open_perror(const char *path, int oflag, mode_t mode);

void	lmt_perror(const char *str);

#endif
