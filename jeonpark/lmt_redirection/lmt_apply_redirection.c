/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 21:09:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// exit(), NULL, close()
#include <fcntl.h>	// open()
#include <unistd.h>	// dup(), dup2()
#include "lmt_apply_redirection.h"

//	인자로 들어온 token 을 적용시킨다
int	lmt_apply_redirection(t_token *token, int should_backup)
{
	int	old_fd;
	int	duplicated_fd;
	int	new_fd;

	new_fd = -2;
	if (token->type == TYPE_REDIRECTION_IN)
	{
		old_fd = FD_IN;
		new_fd = open(token->token[1], O_RDONLY);
	}
	else if (token->type == TYPE_REDIRECTION_WORD)
	{
		// 따로 작동 구현
		old_fd = FD_IN;
		new_fd = FD_NONE;
	}
	else if (token->type == TYPE_REDIRECTION_OUT)
	{
		old_fd = FD_OUT;
		new_fd = open(token->token[1], O_WRONLY | O_CREAT | O_TRUNC, DEFAULT_MODE);
	}
	else if (token->type == TYPE_REDIRECTION_APPEND)
	{
		old_fd = FD_OUT;
		new_fd = open(token->token[1], O_WRONLY | O_CREAT | O_APPEND, DEFAULT_MODE);
	}
	if (new_fd == FD_NONE)
		return (-1);	// 이 반환값을 통해 caller 가 에러를 처리하는가?, 여기서 perror() 를 출력하자
	if (should_backup)
		duplicated_fd = dup(old_fd);
	if (dup2(new_fd, old_fd) == -1)
	{
		if (should_backup)
			close(duplicated_fd);
		return (-1);	// 여기서 perror 를 띄우자, 그런데 숫자를 문자로 바꿔야 하기 때문에 lmt_perror_in() 등을 만들어서 사용하자
	}
	close(new_fd);
	if (should_backup)
		return (duplicated_fd);
	else
		return (-2);
}
