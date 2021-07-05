/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 10:24:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process.h"

void	lmt_process_set_redidrection(t_lmt_process *p_process, int old_fd, int new_fd, char *new_path)
{
	t_lmt_redirection	*p_redirection;

	// old_fd 는 반드시 IN, OUT, ERR 중 하나여야하며 그 외는 추가 작업 필요
	p_redirection = p_process->redirection_array[old_fd];
	p_redirection->fd = new_fd;
	p_redirection->path = new_path;
}

static void	lmt_process_execute(t_lmt_process *p_process, char **env)
{
	dup2(p_process->std_fd[IN], IN);
	dup2(p_process->std_fd[OUT], OUT);
	dup2(p_process->std_fd[ERR], ERR);
	execve(/*get_real_path(*p_process->argv)*/, p_process->argv, env);
//	if fail, process and exit(?)
}

void	lmt_process_execute(t_lmt_process *p_process, char **env)
{
	pid = fork();
	if (pid == 0)  // 자식
		lmt_process_execute_process(p_process, env);
	else  // 부모
		p_process->pid = pid;
}
