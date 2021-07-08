/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 18:49:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

static void	lmt_process_apply_redirection_list(t_lmt_process *p_process)
{
	lmt_redirection_list_apply(p_process->redirection_list);
}

static void	lmt_process_backup_redirection_list(t_lmt_process *p_process)
{
	lmt_redirection_list_backup(p_process->redirection_list);
}

static void	lmt_process_backdown_redirection_list(t_lmt_process *p_process)
{
	lmt_redirection_list_backdown(p_process->redirection_list);
}

void	lmt_process_append_redirection(t_lmt_process *p_process, t_lmt_redirection *p_redirection)
{
	lmt_redirection_list_append(p_process->redirection_list, p_redirection);
}

void	lmt_process_set(t_lmt_process *p_process)
{
	t_lmt_token	*iterator;
	t_lmt_token	*p_argv_token;
	t_lmt_redirection	*p_element;
	t_lmt_token_sublist	*sublist;

	p_argv_token = NULL;
	iterator = p_process->token_sublist->first;
	while (iterator != p_process->token_sublist->last)
	{
		if (iterator->type == TYPE_COMMAND)
		{
			if (p_argv_token == NULL)
				p_argv_token = iterator;
			else
				lmt_token_append_token(p_argv_token, iterator);
		}
		else if (lmt_is_type_redirection(iterator->type))
		{
			p_element = lmt_redirection_new_by_string_array(iterator->array);
			lmt_redirection_list_append(p_process->redirection_list, p_element);
		}
		else
			lmt_exit(-1, LMT_WRONG_PATH);
		iterator = iterator->next;
	}

	sublist = lmt_token_sublist_new(p_argv_token, p_argv_token->next);
	lmt_token_sublist_free(p_process->token_sublist);
	p_process->token_sublist = sublist;
}

char	**lmt_process_argv(t_lmt_process *p_process)
{
	return (p_process->token_sublist->first->array->array);
}

int	lmt_process_execute_builtin(t_lmt_process *p_process)
{
	int	return_value;

	lmt_process_set(p_process);
	lmt_process_backup_redirection_list(p_process);
	return_value = 0; //	return_value = call_builtin_function(lmt_process_argv(p_process)[0]);
	lmt_process_backdown_redirection_list(p_process);
	return (return_value);
}

static void	lmt_process_execute_child(t_lmt_process *p_process, char **env)
{
	int	ret;

	if (p_process->type == TYPE_PROCESS_NORMAL)
	{
		lmt_process_set(p_process);
		lmt_process_apply_redirection_list(p_process);
		if (1 /* if p_process->argv[0] is external_command */)
			execve(lmt_process_argv(p_process)[0] /* get_real_path(*p_process->argv) */, lmt_process_argv(p_process), env);
		else
		{
			printf("[%s: Enter message for not a command error] \n", lmt_process_argv(p_process)[0]);
			exit(127);
		}
	}
	else if (p_process->type == TYPE_PROCESS_SHELL)
	{
		lmt_process_apply_redirection_list(p_process);
		ret = lmt_process_manager_execute(p_process->token_sublist, env);
		exit(ret);
	}
	else
		lmt_exit(-1, LMT_WRONG_PATH);
}

void	lmt_process_execute(t_lmt_process *p_process, char **env)
{
	p_process->pid = fork();
	if (p_process->pid == 0)
		lmt_process_execute_child(p_process, env);
}
