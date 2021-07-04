/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 14:57:30 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command.h"

static void	lmt_command_apply_redirection(t_lmt_command *p_command)
{
	(void)p_command;
}

static void	lmt_command_execute_command(t_lmt_command *p_command, char **env)
{
	dup2(p_command->std_fd[IN], IN);
	dup2(p_command->std_fd[OUT], OUT);
	dup2(p_command->std_fd[ERR], ERR);
//	execve(get_real_path(*p_command->argv), p_command->argv, env);
//	if fail, process and exit
}

void	lmt_command_execute_commands(t_lmt_command *p_command, char **env)
{
	int	fd_pipe[2];

	while (p_command != NULL)
	{
		if (p_command->next != NULL)
		{
			if (pipe(fd_pipe) == -1)
//				error_exit();
			p_command->std_fd[OUT] = fd_pipe[PIPE_WRITE];
			p_command->next->std_fd[IN] = fd_pipe[PIPE_READ];
		}
		pid = fork();
		if (pid == 0)  // 자식
		{
			lmt_command_apply_redirectioin(p_command);
			lmt_command_execute_command(p_command, env);
		}
		else  // 부모
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			p_command->pid = pid;
			p_command = p_command->next;
			continue;
		}
	}
}
