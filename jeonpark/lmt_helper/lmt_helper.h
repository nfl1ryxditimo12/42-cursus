/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 14:15:50 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_HELPER_H
# define LMT_HELPER_H

# include <fcntl.h>	// mode_t

int	lmt_count_of_null_terminated_array(void *array);

int	is_type_control_operator(int type);
int	is_type_redirection(int type);
int	is_type_open_parenthesis(int type);
int	is_type_close_parenthesis(int type);
int	is_type_command(int type);

int	lmt_dup_perror(int old_fd);
int	lmt_dup2_perror(int new_fd, int old_fd);

int	lmt_get_exit_code_from_stat_loc(int stat_loc);

int	lmt_open_perror(const char *path, int oflag, mode_t mode);

#endif
