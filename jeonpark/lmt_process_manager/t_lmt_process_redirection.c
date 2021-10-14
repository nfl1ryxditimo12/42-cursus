/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 21:50:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>	// errno
#include "t_lmt_process_manager.h"

static int	attach_io(t_token *redirection_token, t_lmt_process_manager *manager)
{
	int	return_value;

	if (redirection_token->type == TYPE_REDIRECTION_IN)
	{
		lmt_process_manager_dup_std_fd(manager, FD_IN);
		return_value = lmt_attach_redirection(redirection_token);
		if (return_value != NORMAL)
			return (return_value);
	}
	else if (redirection_token->type == TYPE_REDIRECTION_OUT
			|| redirection_token->type == TYPE_REDIRECTION_APPEND)
	{
		lmt_process_manager_dup_std_fd(manager, FD_OUT);
		return_value = lmt_attach_redirection(redirection_token);
		if (return_value != NORMAL)
			return (return_value);
	}
	return (NORMAL);
}

//	여기서는 exit 하지는 않는다. builtin 일 수도 있기 때문이다.
int	lmt_process_attach_io(t_lmt_process *process, t_lmt_process_manager *manager)
{
	t_token	*element;
	int		return_value;

	lmt_process_manager_attach_pipe(manager);
	element = process->token_sublist->first->next;
	while (element != process->token_sublist->terminator)
	{
		return_value = attach_io(element, manager);
		if (return_value != NORMAL)
			return (return_value);
		element = element->next;
	}
	return (NORMAL);
}
