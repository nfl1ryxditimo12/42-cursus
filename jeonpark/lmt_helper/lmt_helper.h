/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_helper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/23 19:33:59 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_HELPER_H
# define LMT_HELPER_H

# include <fcntl.h>	// mode_t
# include <unistd.h>	// pid_t
# include "minishell.h"

void    lmt_convert_list(t_handler *handler);

int		lmt_count_of_null_terminated_array(void **array);

void	lmt_critical_exit();

int		is_type_control_operator(int type);
int		is_type_redirection(int type);
int		is_type_open_parenthesis(int type);
int		is_type_close_parenthesis(int type);
int		is_type_command(int type);

int		lmt_dup_perror(int old_fd);
int		lmt_dup2_perror(int new_fd, int old_fd);

pid_t	lmt_fork_exit();

int		lmt_get_exit_code_from_stat_loc(int stat_loc);

int		lmt_open_perror(const char *path, int oflag, mode_t mode);

#endif
