/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 17:42:06 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

void	lmt_process_wait(t_lmt_process *process)
{
	int	stat_loc;
	int	return_value;

	if (process->pid == PID_NONE)
		return ;
	return_value = waitpid(process->pid, &stat_loc, SA_RESTART);
	process->pid = PID_NONE;
	if (return_value == -1)
		process->exit_code = 255;
	else
	{
		process->exit_code = lmt_get_number_of_signal_that_caused_termination(stat_loc);
		if (process->exit_code != 0)
			process->exit_code += 128;
		else
			process->exit_code = lmt_get_exit_code_from_stat_loc(stat_loc);
	}
}

static int	should_execute_on_child(t_lmt_process *process, t_handler *handler)
{
	int	return_value;

	return_value = (lmt_process_prev(process) != NULL
			&& lmt_process_prev(process)->next_control_op
			== TYPE_CONTROL_OPERATOR_PIPE)
		|| process->next_control_op == TYPE_CONTROL_OPERATOR_PIPE;
	handler->line = process->token_sublist->first;
	if (builtin_cmd(handler))
		return (return_value);
	return_value |= not_builtin_cmd(handler);
	return (return_value);
}

static void	process_execute(t_lmt_process *process, t_lmt_process_manager *manager)
{
	manager->handler->line = process->token_sublist->first;
	if (builtin_cmd(manager->handler))
	{
		process_builtin_cmd(manager->handler);
		process->exit_code = manager->handler->status;
	}
	else if (not_builtin_cmd(manager->handler))
	{
		lmt_refine_token_argv_0(process->token_sublist->first);
		execve(manager->handler->line->cmd_dir, process->token_sublist->first->token, manager->handler->env);
	}
	else
	{
		lmt_perror(process->token_sublist->first->token[0]);
		process->exit_code = 127;
	}
	if (process->pid == 0)
		exit(process->exit_code);
}

int	lmt_process_execute(t_lmt_process *process, t_lmt_process_manager *manager)
{
	int	return_value;

	return_value = lmt_process_attach_io(process, manager);
	if (return_value != NORMAL)
		return (return_value);
	if (process->token_sublist->first->token[0] == NULL)
		process->token_sublist->first->token[0] = ft_strdup("more");
	if (should_execute_on_child(process, manager->handler))
	{
		process->pid = lmt_fork_exit();
		if (process->pid > 0)
			return (NORMAL);
		signal_set_status(STATUS_CHILD);
	}
	process_execute(process, manager);
	return (NORMAL);
}
