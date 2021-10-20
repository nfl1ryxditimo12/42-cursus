/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 15:40:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_H
# define T_LMT_PROCESS_H

# include <unistd.h>	// pid_t
# include "lmt_process_manager_typedef.h"

typedef struct s_lmt_process
{
	int						type;
	t_lmt_token_sublist		*token_sublist;
	int						next_control_op;
	pid_t					pid;
	struct s_lmt_process	*prev;
	struct s_lmt_process	*next;
}	t_lmt_process;

//	type function
t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist);
void			lmt_process_free(t_lmt_process *process);

//	method function
int		lmt_process_execute_in_parent(t_lmt_process *process, t_lmt_process_manager *manager);
int		lmt_process_execute_child(t_lmt_process *process, t_lmt_process_manager *manager);

int		lmt_process_attach_io(t_lmt_process *process, t_lmt_process_manager *manager);

#endif
