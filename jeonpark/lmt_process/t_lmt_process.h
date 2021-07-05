/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 10:12:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_H
# define T_LMT_PROCESS_H

# include "lmt_env_path_array.h"

typedef struct s_lmt_process
{
	char	**argv;
	t_lmt_redirection	**redirection_array;
	pid_t	pid;
	struct s_lmt_process	*next;
}	t_lmt_process;

//	type function
t_lmt_process	*lmt_process_new(char **argv, t_lmt_redirection **redirection_array);
void			lmt_process_free(t_lmt_process *p_process);

//	method function
void	lmt_process_set_redidrection(t_lmt_process *p_process, int old_fd, int new_fd, char *new_path);

#endif
