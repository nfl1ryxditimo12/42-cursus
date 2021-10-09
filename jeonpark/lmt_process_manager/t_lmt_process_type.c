/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 20:00:14 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"

//	stdlib.h: free()

static t_lmt_process	*lmt_process_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process)));
}

static void	lmt_process_init(t_lmt_process *p_process, int type, t_lmt_token_sublist *token_sublist)
{
	p_process->type = type;
	p_process->token_sublist = token_sublist;
	p_process->redirection_list = lmt_redirection_list_new();
	if (token_sublist->terminator == NULL)
		p_process->next_operator = TYPE_TERMINATOR;
	else
		p_process->next_operator = token_sublist->terminator->type;
}

t_lmt_process	*lmt_process_new(int type, t_lmt_token_sublist *token_sublist)
{
	t_lmt_process	*p_process;

	p_process = lmt_process_alloc();
	lmt_process_init(p_process, type, token_sublist);
	return (p_process);
}

void	lmt_process_free(t_lmt_process *p_process)
{
	lmt_token_sublist_free(p_process->token_sublist);
	lmt_redirection_list_free(p_process->redirection_list, REDIRECTION_FREE);
	free(p_process);
}
