/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 22:15:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "t_lmt_process_list.h"
#include "t_lmt_process.h"
#include "lmt_util.h"

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
	int	exit_code;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == OPERATOR_PIPE || iterator->op == OPERATOR_NONE)
			waitpid(iterator->pid, &stat_loc, 0);
		iterator = iterator->next;
	}
	return (lmt_get_exit_code_from_stat_loc(stat_loc));
}

int	lmt_process_list_execute(t_lmt_process_list *list, char **env)
{
	t_lmt_process	*iterator;
	int	fd_pipe[2];
	int	stat_loc;
	int	exit_code;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == OPERATOR_PIPE)
		{
			if (pipe(fd_pipe) == -1)
				lmt_exit(0, "Pipe error has occured \n");
			lmt_process_append_redirection(iterator, fd_pipe[PIPE_WRITE], NULL, STANDARD_OUT);
			lmt_process_append_redirection(iterator, fd_pipe[PIPE_READ], NULL, STANDARD_IN);
			lmt_process_execute(iterator, env);
			close(fd_pipe[PIPE_WRITE]);
			lmt_redirection_list_append(list->redirection_to_close_list,
					lmt_redirection_new(fd_pipe[PIPE_READ], -1, -1, NULL));
		}
		else if (iterator->op != OPERATOR_NONE)
		{
			lmt_process_execute(iterator, env);
			waitpid(iterator->pid, &stat_loc, 0);
			exit_code = lmt_get_exit_code_from_stat_loc(stat_loc);
			if ((iterator->op == OPERATOR_AND && exit_code == 0)
					|| (iterator->op == OPERATOR_OR && exit_code != 0))
				return (exit_code);
		}
		else
			lmt_process_execute(iterator, env);
		iterator = iterator->next;
	}
	exit_code = lmt_process_list_wait(list);
	return (exit_code);
}

in_the_while_loop(/* something */)
{
	return (iterator != token_sublist->last);
}

static void	lmt_process_list_set_by_lmt_token_sublist(t_lmt_process_list *list, t_lmt_token_sublist *token_sublist)
{
	t_lmt_token	*iterator;

	iterator = token_sublist->first;
	while (in_the_while_loop(/* something */))
	{
		lmt_process_new_by_lmt_token(token_sublist);
		iterator = iterator->next;
	}
//	이 함수 구현하기
}
