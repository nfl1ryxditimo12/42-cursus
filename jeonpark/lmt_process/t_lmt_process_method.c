/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 17:15:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process.h"

static void	lmt_process_apply_redirection(t_lmt_process *p_process)
{
	(void)p_process;
}

static void	lmt_process_execute_process(t_lmt_process *p_process, char **env)
{
	dup2(p_process->std_fd[IN], IN);
	dup2(p_process->std_fd[OUT], OUT);
	dup2(p_process->std_fd[ERR], ERR);
//	execve(get_real_path(*p_process->argv), p_process->argv, env);
//	if fail, process and exit
}

void	lmt_process_execute_processs(t_lmt_process *p_process, char **env)
{
	int	fd_pipe[2];

	while (p_process != NULL)
	{
		if (p_process->next != NULL)
		{
			if (pipe(fd_pipe) == -1)
//				error_exit();
			p_process->std_fd[OUT] = fd_pipe[PIPE_WRITE];
			p_process->next->std_fd[IN] = fd_pipe[PIPE_READ];
		}
		pid = fork();
		if (pid == 0)  // 자식
		{
			lmt_process_apply_redirectioin(p_process);
			lmt_process_execute_process(p_process, env);
		}
		else  // 부모
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			p_process->pid = pid;
			p_process = p_process->next;
			continue;
		}
	}
}
