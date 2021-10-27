/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_execute.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:08:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 16:12:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

static void	set_pipe(t_lmt_process *process, t_lmt_process_manager *manager)
{
	if (process->next_control_op == TYPE_CONTROL_OPERATOR_PIPE)
		lmt_process_manager_set_pipe(manager);
	lmt_process_manager_attach_pipe(manager);
}

static int	lmt_process_list_get_exit_code(t_lmt_process *dummy)
{
	int				exit_code;
	t_lmt_process	*element;

	exit_code = -1;
	element = dummy->next;
	while (element != dummy)
	{
		if (element->pid == PID_NONE)
		{
			if (element->exit_code == -1)
			{
				if (element->type == TYPE_PROCESS_PARENTHESIS)
					element->exit_code
						= lmt_process_list_get_exit_code(element->list);
				else
					return (exit_code);
			}
		}
		else
			lmt_process_wait(element);
		exit_code = element->exit_code;
		element = element->next;
	}
	return (exit_code);
}

static int	should_stop_control_operator_or_and(t_lmt_process *process)
{
	int	exit_code;

	if (!(process->next_control_op == TYPE_CONTROL_OPERATOR_AND
			|| process->next_control_op == TYPE_CONTROL_OPERATOR_OR))
		return (FALSE);
	exit_code = lmt_process_list_get_exit_code(lmt_process_dummy(process));
	if (process->next_control_op == TYPE_CONTROL_OPERATOR_AND)
		if (exit_code != EXIT_CODE_TRUE)
			return (TRUE);
	if (process->next_control_op == TYPE_CONTROL_OPERATOR_OR)
		if (exit_code == EXIT_CODE_TRUE)
			return (TRUE);
	return (FALSE);
}

t_lmt_process	*lmt_process_next_to_execute(t_lmt_process *process)
{
	t_lmt_process	*dummy;

	if (!should_stop_control_operator_or_and(process))
		return (lmt_process_next(process));
	dummy = lmt_process_dummy(process);
	if (dummy->list == NULL)
		return (NULL);
	return (lmt_process_next_to_execute(dummy->list));
}

void	lmt_process_list_execute(
		t_lmt_process *dummy, t_lmt_process_manager *manager)
{
	t_lmt_process	*element;
	int				return_value;

	element = lmt_process_next(dummy);
	while (element != NULL)
	{
		set_pipe(element, manager);
		return_value = lmt_process_execute(element, manager);
		if (return_value != NORMAL)
			element->exit_code = 1;
		lmt_process_manager_consume_fd_pipe(manager);
		lmt_process_manager_restore_fd_std(manager);
		element = lmt_process_next_to_execute(element);
	}
	manager->handler->status = lmt_process_list_get_exit_code(dummy);
}
