/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_method.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 12:55:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include "t_lmt_process_manager.h"

//	fcntl.h: open()
//	stddef.h: NULL

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

///	Applies parameter 'p_redirection' and returns the duplicated fd of fd_old of p_redirection
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

t_lmt_redirection	*lmt_redirection_new_by_string_array(t_lmt_string_array *array)
{
	int	fd_new;
	char	*path_new;
	int	type;
	int	fd_old;
	t_lmt_redirection	*p_redirection;
	int	return_value;

	if (array->count == 2)
	{
		fd_new = -1;
		if (**array->array == '<')
		{
			fd_old = FD_IN;
			type = TYPE_REDIRECTION_IN;
		}
		else if (**array->array == '>')
		{
			fd_old = FD_OUT;
			type = TYPE_REDIRECTION_OUT;
		}
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd_new = -1;
			path_new = NULL;
			type = TYPE_NONE;
			fd_old = -1;
		}
		path_new = array->array[1];
	}
	else if (array->count == 3)
	{
		fd_new = -1;
		return_value = lmt_atoi(array->array[0], &fd_old);
		if (return_value == PARSE_FAIL)
			lmt_exit(-1, LMT_WRONG_PATH);
		if (*array->array[1] == '<')
			type = TYPE_REDIRECTION_IN;
		else if (*array->array[1] == '>')
			type = TYPE_REDIRECTION_OUT;
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd_new = -1;
			path_new = NULL;
			type = TYPE_NONE;
			fd_old = -1;
		}
		path_new = array->array[1];
	}
	else
	{
		lmt_exit(-1, LMT_WRONG_PATH);
		fd_new = -1;
		path_new = NULL;
		type = TYPE_NONE;
		fd_old = -1;
	}
	p_redirection = lmt_redirection_new(fd_old, type, fd_new, path_new);
	return (p_redirection);
}
