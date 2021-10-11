/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:32:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	lmt_process 의 token_sublist 를 순차적으로 돌면서
//	redirection 들을 list 에 추가한다
static void	lmt_process_set(t_lmt_process *process)
{
	t_token				*iterator;
	t_token				*p_command_token;
	t_lmt_redirection	*p_element;

	iterator = process->token_sublist->first;
	while (iterator != process->token_sublist->terminator)
	{
		if (iterator->type == TYPE_COMMAND)
			p_command_token = iterator;
		else if (lmt_is_token_type_redirection(iterator))
		{
			p_element = lmt_redirection_new_by_token(iterator);
			lmt_redirection_list_append(process->redirection_list, p_element);
		}
		else
			exit(1);
		iterator = iterator->next;
	}
	process->token_sublist->first = p_command_token;
	process->token_sublist->terminator = p_command_token->next;
}

//	(가명) seonkim_builtin_function(t_handler) 를 호출하는 함수이다
//	parent 가 command 를 실행하는 함수를 호출하여
//	parent 상에서 command 가 실행한다
//	앞 lmt_process 의 op 가 '|' 가 아니고,
//	현재 lmt_process 의 op 가 '||' 나 '&&' 이거나 'TYPE_NONE' 인 경우
//	builtin command 는 parent 상에서 실행되어야 한다
//	저번에 zsh 과 bash 에서 'cd ..' 의 차이가 나는 부분은 '|' 뿐이었다
int	lmt_process_execute_parent(t_lmt_process *process, t_handler *handler)
{
	int	exit_code;

	lmt_process_set(process);
	lmt_process_backup_redirection_list(process);
	exit_code = 0;
	(void)handler;
//	exit_code = seonkim_builtin_function(handler);
	lmt_process_backdown_redirection_list(process);
	return (exit_code);
}

//	process_line(handler) 를 호출하는 함수이다
//	lmt_process_list_set_by_token_sublist() 에서 설정한
//	lmt_process 의 type 에 따라 바로 명령을 실행하기도 하고
//	재귀적으로 다시 lmt_process_manager_execute() 를 호출하기도 한다
void	lmt_process_execute_child(t_lmt_process *process, t_handler *handler)
{
	int					ret;
	t_lmt_redirection	*p_redirection;

	process->pid = fork();
	if (process->pid == -1)
		exit(1);
	if (process->pid > 0)
	{
		p_redirection = process->redirection_list->p_dummy->next;
		if (process->prev->next_control_op == TYPE_CONTROL_OPERATOR_PIPE)
		{
			close(p_redirection->fd_new);
			p_redirection = p_redirection->next;
		}
		if (process->next_control_op == TYPE_CONTROL_OPERATOR_PIPE)
			close(p_redirection->fd_new);
		return ;
	}
	if (process->type == TYPE_PROCESS_NORMAL)
	{
		lmt_process_set(process);
		lmt_process_apply_redirection_list(process);
		//	process->token_sublist->first[0] 가 항상 command 인 것은 아니다(redirection 일 수도 있다)
		//	이후에 잘 정리가 되면 이 부분을 수정하도록 하자.
		//	우선은 가장 처음에 redirection 이 절대 오지 않으며, command 가 나온다고 가정.
		handler->line = process->token_sublist->first;
		if (builtin_cmd(handler))
			process_builtin_cmd(handler);
		else if (not_builtin_cmd(handler))
		{
			lmt_refine_token_argv_0(process->token_sublist->first);
			execve(handler->line->cmd_dir, process->token_sublist->first->token, handler->env);
		}
		else
		{
			// 실행 가능한 명령이 아님 -> 에러처리
			perror(process->token_sublist->first->token[0]);
			exit (1);
		}
	}
	else if (process->type == TYPE_PROCESS_SUBSHELL)
	{
		lmt_process_apply_redirection_list(process);
		ret = lmt_process_manager_execute_token_sublist(handler, process->token_sublist);
		exit(ret);
	}
	else
		exit(1);
}
