/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/03 22:51:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command.h"

void	lmt_command_run(t_lmt_command *p_command, char **env)
{
	int	fd_pipe[2];

	while (p_command != NULL)
	{
		if (p_command->next != NULL)
		{
			if (pipe(fd_pipe) == -1)
				// error_exit
			dup2(p_command->std_fd[OUT], 
		}
		pid = fork();
		if (pid == 0)  // 자식
		{
			close(STDIN);
			close(STDOUT);
			close(STDERR);
			dup2(p_command->std_fd[IN], IN);
			dup2(p_command->std_fd[OUT], OUT);
			dup2(p_command->std_fd[ERR], ERR);
			execute_command(p_command->argv, env);
			execve(p_command[0], p_command->token, env);
			break ;
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
