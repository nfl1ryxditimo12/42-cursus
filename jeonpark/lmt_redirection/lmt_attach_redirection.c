/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 10:23:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// exit(), NULL
#include <fcntl.h>	// open()
#include <unistd.h>	// dup(), dup2()
#include "lmt_redirection.h"
#include "lmt_helper.h"	// lmt_open_perror(), lmt_dup2_perror()

static void	set_output(t_token *token, int *old_fd, int *new_fd)
{
	if (!(token->type == TYPE_REDIRECTION_OUT
			|| token->type == TYPE_REDIRECTION_APPEND))
		return ;
	*old_fd = FD_OUT;
	if (token->type == TYPE_REDIRECTION_OUT)
		*new_fd = lmt_open_perror(token->token[1],
				O_WRONLY | O_CREAT | O_TRUNC, DEFAULT_MODE);
	else
		*new_fd = lmt_open_perror(token->token[1],
				O_WRONLY | O_CREAT | O_APPEND, DEFAULT_MODE);
}

///	인자로 들어온 token 을 적용시킨다
///	- return value:
///		- -2: normal && not important value
///		- FD_NONE: error
int	lmt_attach_redirection(t_token *token,
		t_lmt_redirection_word_line **word_line, int std_in, int std_out)
{
	int	old_fd;
	int	new_fd;

	new_fd = -2;
	if (token->type == TYPE_REDIRECTION_IN)
	{
		old_fd = FD_IN;
		new_fd = lmt_open_perror(token->token[1], O_RDONLY, 0);
	}
	else if (token->type == TYPE_REDIRECTION_WORD)
	{
		lmt_redirection_word_line_free(*word_line);
		*word_line = lmt_redirection_word_line_new_from_stdin(std_in,
				std_out, token->token[1]);
		return (NORMAL);
	}
	set_output(token, &old_fd, &new_fd);
	if (new_fd == FD_ERROR)
		return (ERROR);
	lmt_dup2_perror(new_fd, old_fd);
	lmt_close(new_fd);
	return (NORMAL);
}
