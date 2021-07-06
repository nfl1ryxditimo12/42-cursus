/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 22:15:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_lmt_redirection.h"
#include "lmt_util.h"

//	unistd.h: close()
//	stddlib.h: free()

static t_lmt_redirection	*lmt_redirection_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection)));
}

static void	lmt_redirection_init(t_lmt_redirection *p_redirection, int fd, int type, int fd2)
{
	p_redirection->fd = fd;
	p_redirection->type = type;
	p_redirection->fd2 = fd2;
}

t_lmt_redirection	*lmt_redirection_new(int fd, int type, int fd2, char *path)
{
	t_lmt_redirection	*p_redirection;

	p_redirection = lmt_redirection_alloc();
	lmt_redirection_init(p_redirection, fd, type, fd2);
	p_redirection->path = path;
	return (p_redirection);
}

void	lmt_redirection_free(t_lmt_redirection *p_redirection, int option)
{
	//	path 는 어디서 free 하는가?
	if (option == REDIRECTION_FREE_FD)
		close(p_redirection->fd);
	free(p_redirection);
}

int	lmt_redirection_apply(t_lmt_redirection *p_redirection)
{
	if (p_redirection->path != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			fd = open(p_redirection->path, O_RDONLY);
		else
			return (lmt_return_error(LMT_WRONG_PATH);
		if (fd == -1)
			return (lmt_return_error(p_redirection->path))
		dup2(fd, p_redirection->fd2);
	}
	else
		dup2(p_redirection->fd, p_redirection->fd2);
}

lmt_redirection	*lmt_redirection_new_by_token(t_lmt_token *p_token)
{
	char	redirection_ch;
	char	*p_ch;

	if (p_token->type == TYPE_REDIRECTION_IN)
		redirection_ch = '<';
	else if (p_token->type == TYPE_REDIRECTION_OUT)
		redirection_ch = '>';
//	이 함수 구현하기
}
