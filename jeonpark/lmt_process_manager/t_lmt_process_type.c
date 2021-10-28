/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 10:04:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// NULL
#include "t_lmt_process_manager.h"

//	stdlib.h: free()

static t_lmt_process	*lmt_process_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process)));
}

static void	lmt_process_init(t_lmt_process *process,
		int type, t_lmt_token_sublist *token_sublist)
{
	process->type = type;
	process->token_sublist = token_sublist;
	process->next_control_op
		= lmt_token_sublist_get_next_control_op(token_sublist);
	process->pid = PID_NONE;
	process->exit_code = -1;
	process->list = NULL;
}

t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist)
{
	t_lmt_process	*process;

	process = lmt_process_alloc();
	lmt_process_init(process, type, token_sublist);
	return (process);
}

void	lmt_process_free(t_lmt_process *process)
{
	lmt_token_sublist_free(process->token_sublist);
	free(process);
}
