/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:37:29 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// close()
#include <stdlib.h>	// free()
#include "t_lmt_redirection.h"

static t_lmt_redirection	*lmt_redirection_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection)));
}

static void	lmt_redirection_init(t_lmt_redirection *p_redirection, int type, int new_fd, const char *path)
{
	p_redirection->type = type;
	p_redirection->new_fd = new_fd;
	p_redirection->path = path;
}

t_lmt_redirection	*lmt_redirection_new(int type, int new_fd, const char *path)
{
	t_lmt_redirection	*p_redirection;

	p_redirection = lmt_redirection_alloc();
	lmt_redirection_init(p_redirection, type, new_fd, path);
	return (p_redirection);
}

//	- 인자:
//		- p_redirection: free 할 lmt_redirection
//		- option:
//			- REDIRECTION_FREE: 각 redirection 의 new_fd 를 close 하지 않는다
//			- REDIRECTION_FREE_CLOSE_FD: 각 redirection 의 new_fd 를 close 한다
void	lmt_redirection_free(t_lmt_redirection *p_redirection, int option)
{
	if (option == REDIRECTION_FREE_CLOSE_FD)
		close(p_redirection->new_fd);
	free(p_redirection);
}
