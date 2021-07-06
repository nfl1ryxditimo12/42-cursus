/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 22:14:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process.h"
#include "t_lmt_redirection_list.h"
#include "lmt_util.h"

void	lmt_process_append_redirection(t_lmt_process *p_process, int fd, char *path, int fd2)
{
	lmt_redirection_list_append(p_process->redirection_list, fd, path, fd2);
}

static void	lmt_process_execute_child(t_lmt_process *p_process, char **env)
{
	int	ret;

	lmt_redirection_list_apply(p_process->redirection_list);
	if (p_process->type == TYPE_PROCESS_NORMAL)
		//	if fail, process and exit(true or false)
		execve(p_process->argv[0] /* get_real_path(*p_process->argv) */, p_process->argv, env);
	else if (p_process->type == TYPE_PROCESS_SHELL)
	{
		ret = lmt_process_manager_execute(p_process->token_list->p_dummy->next);
		exit(ret);
	}
}

void	lmt_process_execute(t_lmt_process *p_process, char **env)
{
	p_process->pid = fork();
	if (p_process->pid == 0)
		lmt_process_execute_child(p_process, env);
}

lmt_process	*lmt_process_new_by_lmt_token_sublist(t_lmt_token *p_token)
{
	t_lmt_token	*previous;
	t_lmt_token	*iterator;
	int	parenthesis_count;

	iterator = p_token;
	if (iterator->type == TYPE_PARENTHESIS_OPEN)
	{
		iterator = iterator->next;
		parenthesis_count = 1;
		while (parenthesis_count > 0)
		{
			if (iterator->type == TYPE_PARENTHESIS_OPEN)
				++parenthesis_count;
			else if (iterator->type == TYPE_PARENTHESIS_CLOSE)
				--parenthesis_count;
			previous = iterator;
			iterator = previous->next;
		}
		return (lmt_process_new(TYPE_PROCESS_SHELL, lmt_token_sublist_new(sublist->first, previous), iterator->next->type));
	}
//	아래의 pseudo code 를 구현하기
//	while (not op)
//		append;
//	return (process_new);
}
