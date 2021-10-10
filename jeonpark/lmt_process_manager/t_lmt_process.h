/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 15:21:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_H
# define T_LMT_PROCESS_H

# include <unistd.h>
# include "lmt_process_manager_typedef.h"

//	unistd.h: pid_t

typedef struct s_lmt_process
{
	int						type;
	t_lmt_token_sublist		*token_sublist;
	int						next_operator;
	t_lmt_redirection_list	*redirection_list;
	pid_t					pid;
	struct s_lmt_process	*prev;
	struct s_lmt_process	*next;
}	t_lmt_process;

//	type function
t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist);
void			lmt_process_free(t_lmt_process *p_process);

//	method function
int	lmt_process_execute_parent(t_lmt_process *p_process, t_handler *p_handler);
void	lmt_process_execute_child(t_lmt_process *p_process, t_handler *p_handler);

void	lmt_process_apply_redirection_list(t_lmt_process *p_process);
void	lmt_process_backup_redirection_list(t_lmt_process *p_process);
void	lmt_process_backdown_redirection_list(t_lmt_process *p_process);
void	lmt_process_append_redirection(t_lmt_process *p_process, t_lmt_redirection *p_redirection);
int		lmt_process_append_pipe_redirection(t_lmt_process *p_process);

#endif
