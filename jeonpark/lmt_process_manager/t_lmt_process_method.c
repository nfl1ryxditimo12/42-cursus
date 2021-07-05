/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:41 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 12:02:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_lmt_process.h"
#include "t_lmt_redirection.h"
#include "lmt_util.h"

void	lmt_process_set_redirection(t_lmt_process *p_process, int old_fd, int new_fd, char *new_path)
{
	t_lmt_redirection	*p_redirection;

	// old_fd 는 반드시 IN, OUT, ERR 중 하나여야하며 그 외는 추가 작업 필요
	p_redirection = p_process->redirection_array[old_fd];
	p_redirection->fd = new_fd;
	p_redirection->path = new_path;
}

static void	lmt_process_execute_child(t_lmt_process *p_process, char **env)
{
	// path 면 path 로 fd 를 만들고 복제하도록 하기
	// path 가 /dev/fd/1 등일 때 open 해도 잘 작동하는가?
	dup2(p_process->redirection_array[IN]->fd, IN);
	dup2(p_process->redirection_array[OUT]->fd, OUT);
	dup2(p_process->redirection_array[ERR]->fd, ERR);
	execve("/bin/cat" /* get_real_path(*p_process->argv) */, p_process->argv, env);
//	if fail, process and exit(?)
}

void	lmt_process_execute(t_lmt_process *p_process, char **env)
{
	p_process->pid = fork();
	if (p_process->pid == 0)  // 자식
		lmt_process_execute_child(p_process, env);
}
