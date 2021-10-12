/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 11:04:32 by jeonpark         ###   ########.fr       */
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
		return(-1);
	process->pipe_fd_out = pipe_fd[PIPE_WRITE];
	process->next->pipe_fd_in = pipe_fd[PIPE_READ];
	return (0);
}

int	lmt_process_apply_redirection(t_lmt_process *process)
{
	t_token	*element;

	lmt_apply_pipe_redirection(process);
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
