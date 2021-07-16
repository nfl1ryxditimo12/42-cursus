/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 17:51:55 by jeonpark         ###   ########.fr       */
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

//	lmt_process 의 token_sublist 를 순차적으로 돌면서
//	redirection 들을 list 에 추가한다
void	lmt_process_set(t_lmt_process *p_process)
{
	t_token				*iterator;
	t_token				*p_command_token;
	t_lmt_redirection	*p_element;

	iterator = p_process->token_sublist->first;
	while (iterator != p_process->token_sublist->last)
	{
		if (iterator->type == TYPE_COMMAND)
			p_command_token = iterator;
		else if (lmt_is_token_type_redirection(iterator))
		{
			p_element = lmt_redirection_new_by_token(iterator);
			lmt_redirection_list_append(p_process->redirection_list, p_element);
		}
		else
			lmt_exit(-1, LMT_WRONG_PATH);
		iterator = iterator->next;
	}
	p_process->token_sublist->first = p_command_token;
	p_process->token_sublist->last = p_command_token->next;
}

//	(가명) seonkim_builtin_function(t_handler) 를 호출하는 함수이다
//	parent 가 command 를 실행하는 함수를 호출하여
//	parent 상에서 command 가 실행한다
//	앞 lmt_process 의 op 가 '|' 가 아니고,
//	현재 lmt_process 의 op 가 '||' 나 '&&' 이거나 'TYPE_NONE' 인 경우
//	builtin command 는 parent 상에서 실행되어야 한다
//	저번에 zsh 과 bash 에서 'cd ..' 의 차이가 나는 부분은 '|' 뿐이었다
int	lmt_process_execute_parent(t_lmt_process *p_process, t_handler *p_handler)
{
	int	return_value;

	lmt_process_set(p_process);
	lmt_process_backup_redirection_list(p_process);
	return_value = 0;
	(void)p_handler;
//	return_value = seonkim_builtin_function(p_handler);
	lmt_process_backdown_redirection_list(p_process);
	return (return_value);
}

//	process_line(p_handler) 를 호출하는 함수이다
//	lmt_process_list_set_by_token_sublist() 에서 설정한
//	lmt_process 의 type 에 따라 바로 명령을 실행하기도 하고
//	재귀적으로 다시 lmt_process_manager_execute() 를 호출하기도 한다
void	lmt_process_execute_child(t_lmt_process *p_process, t_handler *p_handler)
{
	int	ret;

	p_process->pid = fork();
	if (p_process->pid > 0)
		return ;
	if (p_process->type == TYPE_PROCESS_NORMAL)
	{
		lmt_process_set(p_process);
		lmt_process_apply_redirection_list(p_process);
		process_line(p_handler, p_handler->env);
	}
	else if (p_process->type == TYPE_PROCESS_SUBSHELL)
	{
		lmt_process_apply_redirection_list(p_process);
		ret = lmt_process_manager_execute_token_sublist(p_handler, p_process->token_sublist);
		exit(ret);
	}
	else
		lmt_exit(-1, LMT_WRONG_PATH);
}
