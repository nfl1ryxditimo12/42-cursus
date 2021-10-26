/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:16:25 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 15:43:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

static t_lmt_process_manager	*lmt_process_manager_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process_manager)));
}

static void	lmt_process_manager_init(t_lmt_process_manager *manager, t_handler *handler)
{
	manager->handler = handler;
	manager->fd_pipe[PIPE_READ] = FD_NONE;
	manager->fd_pipe[PIPE_WRITE] = FD_NONE;
	manager->fd_pipe[PIPE_SAVE] = FD_NONE;
	manager->fd_std[FD_IN] = FD_IN;
	manager->fd_std[FD_OUT] = FD_OUT;
}

t_lmt_process_manager	*lmt_process_manager_new(t_handler *handler)
{
	t_lmt_process_manager	*manager;

	manager = lmt_process_manager_alloc();
	lmt_process_manager_init(manager, handler);
	return (manager);
}

void	lmt_process_manager_free(t_lmt_process_manager	*manager)
{
	free(manager);
}
