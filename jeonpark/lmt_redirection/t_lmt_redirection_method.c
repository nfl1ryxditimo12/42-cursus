/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 20:06:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// exit(), NULL
#include <fcntl.h>	// open()
#include "t_lmt_redirection.h"

//	인자로 들어온 p_redirection 을 적용시킨다
void	lmt_redirection_apply(t_lmt_redirection *p_redirection)
{
	int	new_fd;

	if (p_redirection->type == TYPE_REDIRECTION_IN)
		new_fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (p_redirection->type == TYPE_REDIRECTION_WORD)
	{
		new_fd = FD_NONE;
	}
	else if (p_redirection->type == TYPE_REDIRECTION_OUT)
		new_fd = open(p_redirection->path, O_RDONLY);
	else if (p_redirection->type == TYPE_REDIRECTION_APPEND)
		new_fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (new_fd == -1)
	{
		perror(p_redirection->path);
		return ;
	}





	if (p_redirection->path != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			new_fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			new_fd = open(p_redirection->path, O_RDONLY);
		else
		{
			exit(1);
			new_fd = FD_NONE;
		}
		if (new_fd == FD_NONE)
			exit(1);
		dup2(new_fd, p_redirection->fd_old);
		close(new_fd);
	}
	else
	{
		dup2(p_redirection->new_fd, p_redirection->fd_old);
		close(p_redirection->new_fd);
	}
}

//	인자로 들어온 p_redirection 을 적용시키고, p_redirection 의 fd_old 를 복제하여 반환한다
int	lmt_redirection_backup(t_lmt_redirection *p_redirection)
{
	int	duplicated_fd;
	int	new_fd;

	if (p_redirection->path != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			new_fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			new_fd = open(p_redirection->path, O_RDONLY);
		else
		{
			exit(1);
			new_fd = FD_NONE;
		}
		if (new_fd == FD_NONE)
			exit(1);
		duplicated_fd = dup(p_redirection->fd_old);
		dup2(new_fd, p_redirection->fd_old);
		close(new_fd);
	}
	else
	{
		duplicated_fd = dup(p_redirection->fd_old);
		dup2(p_redirection->new_fd, p_redirection->fd_old);
		close(p_redirection->new_fd);
	}
	return (duplicated_fd);
}

//	t_token 을 읽고 lmt_redirection 을 생성하여 반환한다
///	- assume: token's type is redirection
t_lmt_redirection	*lmt_redirection_new_by_token(t_token *token)
{
	return (lmt_redirection_new(token->type, token->token[1]));
}
