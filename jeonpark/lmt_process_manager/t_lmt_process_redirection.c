/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:32:07 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	lmt_process 의 redirection_list 의 redirection 들을 적용시키는 함수
void	lmt_process_apply_redirection_list(t_lmt_process *process)
{
	lmt_redirection_list_apply(process->redirection_list);
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
void	lmt_process_backup_redirection_list(t_lmt_process *process)
{
	t_lmt_redirection_list	*undo_list;

	undo_list = lmt_redirection_list_backup(process->redirection_list);
	lmt_redirection_list_free(process->redirection_list, REDIRECTION_FREE);
	process->redirection_list = undo_list;
}

//	backup 한 redirection_list 를 다시 원래 상태로 되돌리기 위해
//	호출하는 함수
void	lmt_process_backdown_redirection_list(t_lmt_process *process)
{
//	지금은 작동이 이상한 것 같아 수정이 필요하다
	lmt_redirection_list_backdown(process->redirection_list);
}

//	lmt_process 의 redirection_list 에 새로운 redirection node 를
//	append 할 때 호출할 목적으로 만든 함수
void	lmt_process_append_redirection(t_lmt_process *process, t_lmt_redirection *p_redirection)
{
	lmt_redirection_list_append(process->redirection_list, p_redirection);
}

//	pipe 를 연결하는 작동을 수행하도록 현재 lmt_process 와
//	다음 lmt_process 의 redirection_list 에 pipe() 로 받아온
//	fd 값이 설정된 lmt_redirection 을 생성하여 append 해준다
int	lmt_process_append_pipe_redirection(t_lmt_process *process)
{
	int					pipe_fd[2];
	t_lmt_redirection	*p_redirection;

	if (pipe(pipe_fd) == -1)
		exit(1);
	p_redirection = lmt_redirection_new(TYPE_REDIRECTION_OUT, pipe_fd[PIPE_WRITE], NULL);
	lmt_process_append_redirection(process, p_redirection);
	p_redirection = lmt_redirection_new(TYPE_REDIRECTION_IN, pipe_fd[PIPE_READ], NULL);
	lmt_process_append_redirection(process->next, p_redirection);
	//	에러를 없애기 위해 임시 추가
	return (0);
}
