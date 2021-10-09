/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 14:10:12 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	lmt_process 의 redirection_list 의 redirection 들을 적용시키는 함수
static void	lmt_process_apply_redirection_list(t_lmt_process *p_process)
{
	lmt_redirection_list_apply(p_process->redirection_list);
}

//	lmt_process 의 redirection_list 의 redirection 들을 적용시키고
//	redirection 을 적용시키기 전 상태로 되돌리기 위해
//	undo_list 를 설정하는 함수
//
//	- 추가 설명:
//	lmt_process_execute_parent() 의 주석에서 설명한 것과 같이
//	bash 에서도 특정 상태의 builtin command 는 parent 에서 실행되어야 하며
//	이 때 만약 해당 command 에 redirection type 의 token 과 함께 있다면
//	redirection 을 적용한 상태로 command 를 실행한 뒤,
//	다시 원래 상태로 fd 의 연결을 되돌려줄 필요가 있다
static void	lmt_process_backup_redirection_list(t_lmt_process *p_process)
{
	t_lmt_redirection_list	*undo_list;

	undo_list = lmt_redirection_list_backup(p_process->redirection_list);
	lmt_redirection_list_free(p_process->redirection_list, REDIRECTION_FREE);
	p_process->redirection_list = undo_list;
}

//	backup 한 redirection_list 를 다시 원래 상태로 되돌리기 위해
//	호출하는 함수
static void	lmt_process_backdown_redirection_list(t_lmt_process *p_process)
{
//	지금은 작동이 이상한 것 같아 수정이 필요하다
	lmt_redirection_list_backdown(p_process->redirection_list);
}

//	lmt_process 의 redirection_list 에 새로운 redirection node 를
//	append 할 때 호출할 목적으로 만든 함수
void	lmt_process_append_redirection(t_lmt_process *p_process, t_lmt_redirection *p_redirection)
{
	lmt_redirection_list_append(p_process->redirection_list, p_redirection);
}

//	pipe 를 연결하는 작동을 수행하도록 현재 lmt_process 와
//	다음 lmt_process 의 redirection_list 에 pipe() 로 받아온
//	fd 값이 설정된 lmt_redirection 을 생성하여 append 해준다
int	lmt_process_append_pipe_redirection(t_lmt_process *p_process)
{
	int					fd_pipe[2];
	t_lmt_redirection	*p_redirection;

	if (pipe(fd_pipe) == -1)
		exit(1);
	p_redirection = lmt_redirection_new(FD_OUT, TYPE_NONE, fd_pipe[PIPE_WRITE], NULL);
	lmt_process_append_redirection(p_process, p_redirection);
	p_redirection = lmt_redirection_new(FD_IN, TYPE_NONE, fd_pipe[PIPE_READ], NULL);
	lmt_process_append_redirection(p_process->next, p_redirection);
	//	에러를 없애기 위해 임시 추가
	return (0);
}

//	lmt_process 의 token_sublist 를 순차적으로 돌면서
//	redirection 들을 list 에 추가한다
static void	lmt_process_set(t_lmt_process *p_process)
{
	t_token				*iterator;
	t_token				*p_command_token;
	t_lmt_redirection	*p_element;

	iterator = p_process->token_sublist->first;
	while (iterator != p_process->token_sublist->terminator)
	{
		if (iterator->type == TYPE_COMMAND)
			p_command_token = iterator;
		else if (lmt_is_token_type_redirection(iterator))
		{
			p_element = lmt_redirection_new_by_token(iterator);
			lmt_redirection_list_append(p_process->redirection_list, p_element);
		}
		else
			exit(1);
		iterator = iterator->next;
	}
	p_process->token_sublist->first = p_command_token;
	p_process->token_sublist->terminator = p_command_token->next;
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
	int	exit_code;

	lmt_process_set(p_process);
	lmt_process_backup_redirection_list(p_process);
	exit_code = 0;
	(void)p_handler;
//	exit_code = seonkim_builtin_function(p_handler);
	lmt_process_backdown_redirection_list(p_process);
	return (exit_code);
}

//	process_line(p_handler) 를 호출하는 함수이다
//	lmt_process_list_set_by_token_sublist() 에서 설정한
//	lmt_process 의 type 에 따라 바로 명령을 실행하기도 하고
//	재귀적으로 다시 lmt_process_manager_execute() 를 호출하기도 한다
void	lmt_process_execute_child(t_lmt_process *p_process, t_handler *p_handler)
{
	int					ret;
	t_lmt_redirection	*p_redirection;

	p_process->pid = fork();
	if (p_process->pid == -1)
		exit(1);
	if (p_process->pid > 0)
	{
		p_redirection = p_process->redirection_list->p_dummy->next;
		if (p_process->prev->next_operator == TYPE_CONTROL_OPERATOR_PIPE)
		{
			close(p_redirection->fd_new);
			p_redirection = p_redirection->next;
		}
		if (p_process->next_operator == TYPE_CONTROL_OPERATOR_PIPE)
			close(p_redirection->fd_new);
		return ;
	}
	if (p_process->type == TYPE_PROCESS_NORMAL)
	{
		lmt_process_set(p_process);
		lmt_process_apply_redirection_list(p_process);
		//	p_process->token_sublist->first[0] 가 항상 command 인 것은 아니다(redirection 일 수도 있다)
		//	이후에 잘 정리가 되면 이 부분을 수정하도록 하자.
		//	우선은 가장 처음에 redirection 이 절대 오지 않으며, command 가 나온다고 가정.
		p_handler->line = p_process->token_sublist->first;
		if (builtin_cmd(p_handler))
			process_builtin_cmd(p_handler);
		else if (not_builtin_cmd(p_handler))
		{
			lmt_refine_token_argv_0(p_process->token_sublist->first);
			execve(p_handler->line->cmd_dir, p_process->token_sublist->first->token, p_handler->env);
		}
		else
		{
			// 실행 가능한 명령이 아님 -> 에러처리
			perror(p_process->token_sublist->first->token[0]);
			exit (1);
		}
	}
	else if (p_process->type == TYPE_PROCESS_SUBSHELL)
	{
		lmt_process_apply_redirection_list(p_process);
		ret = lmt_process_manager_execute_token_sublist(p_handler, p_process->token_sublist);
		exit(ret);
	}
	else
		exit(1);
}
