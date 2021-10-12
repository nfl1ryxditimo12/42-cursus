/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 21:37:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	pipe 를 연결하는 작동을 수행하도록 현재 lmt_process 와
//	다음 lmt_process 의 redirection_list 에 pipe() 로 받아온
//	fd 값이 설정된 lmt_redirection 을 생성하여 append 해준다
int	lmt_process_set_pipe_redirection(t_lmt_process *process)
{
	int					pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return(ERROR);
	process->pipe_fd_out = pipe_fd[PIPE_WRITE];
	process->next->pipe_fd_in = pipe_fd[PIPE_READ];
	return (NORMAL);
}

static void	lmt_process_apply_pipe(t_lmt_process *process)
{
	if (process->pipe_fd_in != FD_NONE)
	{
		process->backuped_fd_in = dup(FD_IN);
		if (dup2(process->pipe_fd_in, FD_IN) == -1)
		{
			close(process->backuped_fd_in);
			exit (1);	// 여기서 perror 를 띄우자, 그런데 숫자를 문자로 바꿔야 하기 때문에 lmt_perror_in() 등을 만들어서 사용하자
		}
		close(process->pipe_fd_in);
	}
	else if (process->pipe_fd_out != FD_NONE)
	{
		process->backuped_fd_out = dup(FD_OUT);
		if (dup2(process->pipe_fd_out, FD_OUT) == -1)
		{
			close(process->backuped_fd_out);
			exit(1);
		}
		close(process->pipe_fd_out);
	}
}

int	lmt_process_attach_io(t_lmt_process *process)
{
	t_token	*element;

	lmt_process_apply_pipe(process);
	element = process->token_sublist->first->next;
	while (element != process->token_sublist->terminator)
	{
		if (element->type == TYPE_REDIRECTION_IN)
		{
			if (process->backuped_fd_in == -1)
			{
				process->backuped_fd_in = lmt_apply_redirection(element, TRUE);
				if (process->backuped_fd_in == -1)
					return (ERROR);
			}
			else
				lmt_apply_redirection(element, FALSE);
		}
		else if (element->type == TYPE_REDIRECTION_WORD)
			lmt_apply_redirection(element, FALSE);
		else if (element->type == TYPE_REDIRECTION_OUT
				|| element->type == TYPE_REDIRECTION_APPEND)
		{
			if (process->backuped_fd_out == -1)
			{
				process->backuped_fd_out = lmt_apply_redirection(element, TRUE);
				if (process->backuped_fd_in == -1)
					return (ERROR);
			}
			else
				lmt_apply_redirection(element, FALSE);
		}
		element = element->next;
	}
	return (NORMAL);
}

void	lmt_process_restore_redirection(t_lmt_process *process)
{
	if (process->backuped_fd_in != -1)
	{
		dup2(process->backuped_fd_in, FD_IN);
		close(process->backuped_fd_in);
	}
	if (process->backuped_fd_out != -1)
	{
		dup2(process->backuped_fd_out, FD_OUT);
		close(process->backuped_fd_out);
	}
}
