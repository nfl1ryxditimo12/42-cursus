/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 18:25:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "t_lmt_process_manager.h"

//	sys/wait.h: waitpid()

void	lmt_process_list_append(t_lmt_process_list *list, t_lmt_process *p_process)
{
	list->last->next = p_process;
	p_process->next = NULL;
	list->last = p_process;
}

static int	lmt_process_list_wait(t_lmt_process_list *list)
{
	t_lmt_process	*iterator;
	int	stat_loc;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == TYPE_OPERATOR_PIPE || iterator->op == TYPE_NONE)
			if (iterator->pid != 0)
				waitpid(iterator->pid, &stat_loc, 0);
		iterator = iterator->next;
	}
	return (lmt_get_exit_code_from_stat_loc(stat_loc));
}

void	lmt_process_list_set_by_token_sublist(t_lmt_process_list *list, t_lmt_token_sublist *sublist)
{
	t_lmt_token	*p_process_first_token;
	t_lmt_token	*iterator;
	int	parenthesis_count;
	t_lmt_process	*p_element;

	iterator = sublist->first;
	while (iterator != sublist->last)
	{
		if (iterator->type == TYPE_PARENTHESIS_OPEN)
		{
			p_process_first_token = iterator->next;
			parenthesis_count = 1;
			while (parenthesis_count > 0)
			{
				iterator = iterator->next;
				if (iterator->type == TYPE_PARENTHESIS_OPEN)
					++parenthesis_count;
				else if (iterator->type == TYPE_PARENTHESIS_CLOSE)
					--parenthesis_count;
			}
			p_element = lmt_process_new(TYPE_PROCESS_SHELL, lmt_token_sublist_new(p_process_first_token, iterator), iterator->next->type);
			lmt_process_list_append(list, p_element);
			iterator = iterator->next;
		}
		else
		{
			p_process_first_token = iterator;
			while (!lmt_is_type_operator(iterator->type))
				iterator = iterator->next;
			p_element = lmt_process_new(TYPE_PROCESS_NORMAL, lmt_token_sublist_new(p_process_first_token, iterator), iterator->type);
			lmt_process_list_append(list, p_element);
		}
		if (iterator->type != TYPE_NONE)
			iterator = iterator->next;
	}
}

int	lmt_process_list_execute(t_lmt_process_list *list, char **env)
{
	t_lmt_process		*iterator;
	int					fd_pipe[2];
	t_lmt_redirection	*p_redirection;
	int					stat_loc;
	int					exit_code;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == TYPE_OPERATOR_PIPE)
		{
			if (pipe(fd_pipe) == -1)
				lmt_exit(0, "Pipe error has occured \n");
			p_redirection = lmt_redirection_new(fd_pipe[PIPE_WRITE], NULL, -1, FD_OUT);
			lmt_process_append_redirection(iterator, p_redirection);
			p_redirection = lmt_redirection_new(fd_pipe[PIPE_READ], NULL, -1, FD_IN);
			lmt_process_append_redirection(iterator, p_redirection);
			lmt_process_execute(iterator, env);
			close(fd_pipe[PIPE_WRITE]);
			p_redirection = lmt_redirection_new(fd_pipe[PIPE_READ], NULL, -1, -1);
			lmt_redirection_list_append(list->redirection_to_close_list, p_redirection);
		}
		else if (iterator->op != TYPE_NONE)
		{
			lmt_process_set(iterator);
			if (0 /* is_builtin(lmt_process_argv(iterator)[0]) */)
				exit_code = lmt_process_execute_builtin(iterator);
			else
			{
				lmt_process_execute(iterator, env);
				waitpid(iterator->pid, &stat_loc, 0);
				exit_code = lmt_get_exit_code_from_stat_loc(stat_loc);
			}
			if ((iterator->op == TYPE_OPERATOR_AND && exit_code == 0)
					|| (iterator->op == TYPE_OPERATOR_OR && exit_code != 0))
			{
				lmt_process_list_wait(list);
				return (exit_code);
			}
		}
		else
			lmt_process_execute(iterator, env);
		iterator = iterator->next;
	}
	exit_code = lmt_process_list_wait(list);
	return (exit_code);
}
