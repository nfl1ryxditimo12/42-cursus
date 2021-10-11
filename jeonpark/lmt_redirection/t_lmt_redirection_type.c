/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 14:45:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_lmt_redirection.h"

//	unistd.h: close()
//	stddlib.h: free()

static t_lmt_redirection	*lmt_redirection_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection)));
}

static void	lmt_redirection_init(t_lmt_redirection *p_redirection, int fd_old, int type, int fd_new)
{
	p_redirection->fd_old = fd_old;
	p_redirection->type = type;
	p_redirection->fd_new = fd_new;
}

t_lmt_redirection	*lmt_redirection_new(int fd_old, int type, int fd_new, const char *path_new)
{
	t_lmt_redirection	*p_redirection;

	p_redirection = lmt_redirection_alloc();
	lmt_redirection_init(p_redirection, fd_old, type, fd_new);
	p_redirection->path_new = path_new;
	return (p_redirection);
}

//	- 인자:
//		- p_redirection: free 할 lmt_redirection
//		- option:
//			- REDIRECTION_FREE: 각 redirection 의 fd_new 를 close 하지 않는다
//			- REDIRECTION_FREE_CLOSE_FD: 각 redirection 의 fd_new 를 close 한다
void	lmt_redirection_free(t_lmt_redirection *p_redirection, int option)
{
	if (option == REDIRECTION_FREE_CLOSE_FD)
		close(p_redirection->fd_new);
	free(p_redirection);
}
