/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/13 12:09:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// exit(), NULL, close()
#include <stdio.h>	// perror()
#include <fcntl.h>	// open()
#include <unistd.h>	// dup(), dup2()
#include "lmt_apply_redirection.h"
#include "lmt_helper.h"	// lmt_open_perror()

///	인자로 들어온 token 을 적용시킨다
///	- return value:
///		- -2: normal && not important value
///		- FD_NONE: error
int	lmt_apply_redirection(t_token *token, int should_backup)
{
	int	old_fd;
	int	duplicated_fd;
	int	new_fd;

	new_fd = -2;
	if (token->type == TYPE_REDIRECTION_IN)
	{
		old_fd = FD_IN;
		new_fd = lmt_open_perror(token->token[1], O_RDONLY, 0);
	}
	else if (token->type == TYPE_REDIRECTION_WORD)
	{
		// 따로 작동 구현
		old_fd = FD_IN;
		new_fd = -2;
	}
	else if (token->type == TYPE_REDIRECTION_OUT)
	{
		old_fd = FD_OUT;
		new_fd = lmt_open_perror(token->token[1], O_WRONLY | O_CREAT | O_TRUNC, DEFAULT_MODE);
	}
	else if (token->type == TYPE_REDIRECTION_APPEND)
	{
		old_fd = FD_OUT;
		new_fd = lmt_open_perror(token->token[1], O_WRONLY | O_CREAT | O_APPEND, DEFAULT_MODE);
	}
	if (new_fd == FD_NONE)
		return (FD_NONE);
	if (should_backup)
		duplicated_fd = dup(old_fd);
	if (!(token->type == TYPE_REDIRECTION_WORD))
	{
		if (dup2(new_fd, old_fd) == -1)
		{
			if (should_backup)
				close(duplicated_fd);
			perror("dup2");
			return (FD_NONE);
		}
		close(new_fd);
	}
	if (should_backup)
		return (duplicated_fd);
	else
		return (-2);
}
