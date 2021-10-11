/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:32:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"

//	stdlib.h: free()

static t_lmt_process	*lmt_process_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process)));
}

static void	lmt_process_init(t_lmt_process *process, int type, t_lmt_token_sublist *token_sublist)
{
	process->type = type;
	process->token_sublist = token_sublist;
	process->redirection_list = lmt_redirection_list_new();
	if (token_sublist == NULL)
		process->next_control_op = TYPE_UNDEFINED;
	else
	{
		if (token_sublist->terminator == NULL)
			process->next_control_op = TYPE_TERMINATOR;
		else
			process->next_control_op = token_sublist->terminator->type;
	}
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
	lmt_redirection_list_free(process->redirection_list, REDIRECTION_FREE);
	free(process);
}
