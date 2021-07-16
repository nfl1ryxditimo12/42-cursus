/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 16:38:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_H
# define T_LMT_PROCESS_H

# include <unistd.h>
# include "lmt_process_manager_typedef.h"

//	unistd.h: pid_t

typedef struct s_lmt_process
{
	int	type;
	t_lmt_token_sublist	*token_sublist;
	t_lmt_redirection_list	*redirection_list;
	int	op;
	pid_t	pid;
	struct s_lmt_process	*next;
}	t_lmt_process;

//	type function
t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist, int op);
void			lmt_process_free(t_lmt_process *p_process);

//	method function
void	lmt_process_append_redirection(t_lmt_process *p_process, t_lmt_redirection *p_redirection);
void	lmt_process_set(t_lmt_process *p_process);
int	lmt_process_execute_parent(t_lmt_process *p_process, t_handler *p_handler);
void	lmt_process_execute_child(t_lmt_process *p_process, t_handler *p_handler);

#endif
