/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 17:54:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include "t_lmt_process_manager.h"

//	fcntl.h: open()
//	stddef.h: NULL

//	인자로 들어온 p_redirection 을 적용시킨다
void	lmt_redirection_apply(t_lmt_redirection *p_redirection)
{
	int	fd_new;

	if (p_redirection->path_new != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			fd_new = open(p_redirection->path_new, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			fd_new = open(p_redirection->path_new, O_RDONLY);
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd_new = -1;
		}
		if (fd_new == -1)
			lmt_exit(-1, NULL);
		dup2(fd_new, p_redirection->fd_old);
		close(fd_new);
	}
	else
	{
		dup2(p_redirection->fd_new, p_redirection->fd_old);
		close(p_redirection->fd_new);
	}
}

//	인자로 들어온 p_redirection 을 적용시키고, p_redirection 의 fd_old 를 복제하여 반환한다
int	lmt_redirection_backup(t_lmt_redirection *p_redirection)
{
	int	duplicated_fd;
	int	fd_new;

	if (p_redirection->path_new != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			fd_new = open(p_redirection->path_new, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			fd_new = open(p_redirection->path_new, O_RDONLY);
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd_new = -1;
		}
		if (fd_new == -1)
			lmt_exit(-1, NULL);
		duplicated_fd = dup(p_redirection->fd_old);
		dup2(fd_new, p_redirection->fd_old);
		close(fd_new);
	}
	else
	{
		duplicated_fd = dup(p_redirection->fd_old);
		dup2(p_redirection->fd_new, p_redirection->fd_old);
		close(p_redirection->fd_new);
	}
	return (duplicated_fd);
}

//	t_token 을 읽고 lmt_redirection 을 생성하여 반환한다
t_lmt_redirection	*lmt_redirection_new_by_token(t_token *p_token)
{
	int					fd_old;
	int					fd_new;
	char				*path_new;

	fd_old = -1;
	fd_new = -1;
	path_new = NULL;
	if (!lmt_is_token_type_redirection(p_token))
		return (NULL);
	if (p_token->size == 2)
	{
		fd_new = -1;
		if (p_token->type == TYPE_REDIRECTION_IN)
			fd_old = FD_IN;
		else if (p_token->type == TYPE_REDIRECTION_WORD)
			(void)p_token;	// compose code here..
		else if (p_token->type == TYPE_REDIRECTION_OUT)
			fd_old = FD_OUT;
		else if (p_token->type == TYPE_REDIRECTION_APPEND)
			(void)p_token;	// compose code here..
		else
			lmt_exit(-1, LMT_WRONG_PATH);
		path_new = p_token->token[1];
	}
	else if (p_token->size == 3)
	{
		fd_new = -1;
		if (lmt_atoi(p_token->token[0], &fd_old) == PARSE_FAIL)
			lmt_exit(-1, LMT_WRONG_PATH);
		else
			lmt_exit(-1, LMT_WRONG_PATH);
		path_new = p_token->token[1];
	}
	else
		lmt_exit(-1, LMT_WRONG_PATH);
	return (lmt_redirection_new(fd_old, p_token->type, fd_new, path_new));
}
