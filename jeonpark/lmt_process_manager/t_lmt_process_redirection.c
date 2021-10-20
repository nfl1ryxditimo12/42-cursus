/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 15:40:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>	// errno
#include "t_lmt_process_manager.h"

//	여기서는 exit 하지는 않는다. builtin 일 수도 있기 때문이다.
int	lmt_process_attach_io(t_lmt_process *process, t_lmt_process_manager *manager)
{
	t_token	*element;

	if (lmt_process_manager_attach_pipe(manager) == ERROR)
		return (errno);
	element = process->token_sublist->first->next;
	while (element != process->token_sublist->terminator)
	{
		if (element->type == TYPE_REDIRECTION_IN)
		{
			if (lmt_process_manager_dup_std_fd(manager, FD_IN) == ERROR)
				return (ERROR);
			if (lmt_attach_redirection(element) == ERROR)
				return (ERROR);
		}
		else if (element->type == TYPE_REDIRECTION_OUT
				|| element->type == TYPE_REDIRECTION_APPEND)
		{
			if (lmt_process_manager_dup_std_fd(manager, FD_OUT) == ERROR)
				return (ERROR);
			if (lmt_attach_redirection(element) == ERROR)
				return (ERROR);
		}
		element = element->next;
	}
	return (NORMAL);
}
