/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:51:13 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 20:40:46 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// pipe()
#include "t_lmt_process_manager.h"

void	lmt_process_manager_set_pipe(t_lmt_process_manager *manager)
{
	manager->fd_pipe[PIPE_SAVE] = manager->fd_pipe[PIPE_READ];
	if (pipe(manager->fd_pipe) == FD_NONE)
	{
		lmt_perror("pipe");
		exit(EXIT_CODE_FALSE);
	}
}

///	- assume: std_fd must bd FD_IN or FD_OUT
void	lmt_process_manager_dup_std_fd(t_lmt_process_manager *manager, int std_fd)
{
	if (manager->fd_std[std_fd] == std_fd)
		manager->fd_std[std_fd] = lmt_dup_perror(std_fd);
}

///	- dup(FD_IN) rather than dup(manager->fd_std[FD_IN]):
///		- advantage: If there is wrong set as FD_IN, it would occur bug.
///			so, can catch unclosed fd.
void	lmt_process_manager_attach_pipe(t_lmt_process_manager *manager)
{
	if (manager->fd_pipe[PIPE_SAVE] != FD_NONE)
	{
		lmt_process_manager_dup_std_fd(manager, FD_IN);
		lmt_dup2_perror(manager->fd_pipe[PIPE_SAVE], FD_IN);
	}
	if (manager->fd_pipe[PIPE_WRITE] != FD_NONE)
	{
		lmt_process_manager_dup_std_fd(manager, FD_OUT);
		lmt_dup2_perror(manager->fd_pipe[PIPE_WRITE], FD_OUT);
	}
}

void	lmt_process_manager_consume_fd_pipe(t_lmt_process_manager *manager)
{
	lmt_close_fd(&manager->fd_pipe[PIPE_WRITE]);
	lmt_close_fd(&manager->fd_pipe[PIPE_SAVE]);
	manager->fd_pipe[PIPE_SAVE] = manager->fd_pipe[PIPE_READ];
	manager->fd_pipe[PIPE_READ] = FD_NONE;
}

///	- assume: std_fd must bd FD_IN or FD_OUT
static int	lmt_process_manager_restore_fd_std_fd(t_lmt_process_manager *manager, int std_fd)
{
	if (manager->fd_std[std_fd] != std_fd)
	{
		lmt_dup2_perror(manager->fd_std[std_fd], std_fd);
		close(manager->fd_std[std_fd]);
		manager->fd_std[std_fd] = std_fd;
	}
	return (NORMAL);
}

void	lmt_process_manager_restore_fd_std(t_lmt_process_manager *manager)
{
	if (lmt_process_manager_restore_fd_std_fd(manager, FD_IN) == ERROR)
		lmt_critical_exit(ERROR);
	if (lmt_process_manager_restore_fd_std_fd(manager, FD_OUT) == ERROR)
		lmt_critical_exit(ERROR);
}
