/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 19:21:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_redirection.h"
#include "lmt_util.h"

static t_lmt_redirection	*lmt_redirection_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection)));
}

static void	lmt_redirection_init(t_lmt_redirection *p_redirection, int fd, char *path)
{
	p_redirection->fd = fd;
	p_redirection->path = path;
}

t_lmt_redirection	*lmt_redirection_new(int fd, char *path)
{
	t_lmt_redirection	*p_redirection;

	p_redirection = lmt_redirection_alloc();
	lmt_redirection_init(p_redirection, fd, path);
	return (p_redirection);
}

void	lmt_redirection_free(t_lmt_redirection *p_redirection)
{
	// Should free fd and path?
	free(p_redirection);
}
