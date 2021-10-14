/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/25 12:44:54 by jeonpark         ###   ########.fr       */
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
	int						exit_code;
	struct s_lmt_process	*prev;
	struct s_lmt_process	*next;
	struct s_lmt_process	*list;
}	t_lmt_process;

//	type function
t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist);
t_lmt_process	*lmt_process_list_new_by_token_sublist(t_lmt_token_sublist *token_sublist);
void			lmt_process_free(t_lmt_process *process);

//	method function
void	lmt_process_wait(t_lmt_process *process);
int		lmt_process_execute(t_lmt_process *process, t_lmt_process_manager *manager);

//	redirection function
int		lmt_process_attach_io(t_lmt_process *process, t_lmt_process_manager *manager);

#endif
