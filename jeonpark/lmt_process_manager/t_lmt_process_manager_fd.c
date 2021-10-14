/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:51:13 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/14 11:53:00 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// perror()
#include <unistd.h>	// pipe()
#include "t_lmt_process_manager.h"

int	lmt_process_manager_prepare_pipe(t_lmt_process_manager *manager)
{
	manager->fd_pipe[PIPE_SAVE] = manager->fd_pipe[PIPE_READ];
	if (pipe(manager->fd_pipe) == FD_NONE)
	{
		perror("pipe");
		return(ERROR);
	}
	return (NORMAL);
}

void	lmt_process_manager_save_fd_pipe(t_lmt_process_manager *manager)
{
	if (manager->fd_pipe[PIPE_WRITE] != FD_NONE)
		lmt_close(manager->fd_pipe[PIPE_WRITE]);
	manager->fd_pipe[PIPE_WRITE] = FD_NONE;
	if (manager->fd_pipe[PIPE_SAVE] != FD_NONE)
		lmt_close(manager->fd_pipe[PIPE_SAVE]);
	manager->fd_pipe[PIPE_SAVE] = manager->fd_pipe[PIPE_READ];
	manager->fd_pipe[PIPE_READ] = FD_NONE;
}

///	- assume: std_fd must bd FD_IN or FD_OUT
int	lmt_process_manager_dup_std_fd(t_lmt_process_manager *manager, int std_fd)
{
	if (manager->fd_std[std_fd] == std_fd)
	{
		manager->fd_std[std_fd] = lmt_dup_perror(std_fd);
		if (manager->fd_std[std_fd] == FD_NONE)
			return (ERROR);
	}
	return (NORMAL);
}

///	- dup(FD_IN) rather than dup(manager->fd_std[FD_IN]):
///		- advantage: If there is wrong set as FD_IN, it would occur bug.
///			so, can catch unclosed fd.
int	lmt_process_manager_attach_pipe(t_lmt_process_manager *manager)
{
	if (manager->fd_pipe[PIPE_SAVE] != FD_NONE)
	{
		if (lmt_process_manager_dup_std_fd(manager, FD_IN) == ERROR)
			return (ERROR);
		if (lmt_dup2_perror(manager->fd_pipe[PIPE_SAVE], FD_IN) == FD_NONE)
			return (ERROR);
		lmt_close(manager->fd_pipe[PIPE_SAVE]);
		manager->fd_pipe[PIPE_SAVE] = FD_NONE;
	}
	if (manager->fd_pipe[PIPE_WRITE] != FD_NONE)
	{
		if (lmt_process_manager_dup_std_fd(manager, FD_OUT) == ERROR)
			return (ERROR);
		if (lmt_dup2_perror(manager->fd_pipe[PIPE_WRITE], FD_OUT) == FD_NONE)
			return (ERROR);
		lmt_close(manager->fd_pipe[PIPE_WRITE]);
		manager->fd_pipe[PIPE_WRITE] = FD_NONE;
		manager->fd_pipe[PIPE_SAVE] = manager->fd_pipe[PIPE_READ];
		manager->fd_pipe[PIPE_READ] = FD_NONE;
	}
	return (NORMAL);
}

///	- assume: std_fd must bd FD_IN or FD_OUT
static int	lmt_process_manager_restore_std_fd(t_lmt_process_manager *manager, int std_fd)
{
	if (manager->fd_std[std_fd] != std_fd)
	{
		if (lmt_dup2_perror(manager->fd_std[std_fd], std_fd) == FD_NONE)
			return (ERROR);
		close(manager->fd_std[std_fd]);
		manager->fd_std[std_fd] = std_fd;
	}
	return (NORMAL);
}

void	lmt_process_manager_restore_std(t_lmt_process_manager *manager)
{
	if (lmt_process_manager_restore_std_fd(manager, FD_IN) == ERROR)
		lmt_critical_exit(ERROR);
	if (lmt_process_manager_restore_std_fd(manager, FD_OUT) == ERROR)
		lmt_critical_exit(ERROR);
}
