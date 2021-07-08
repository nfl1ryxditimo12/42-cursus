/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:00:51 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "t_lmt_process_manager.h"

//	fcntl.h: open()
//	unistd.h: close()
//	stddlib.h: free()

static t_lmt_redirection	*lmt_redirection_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection)));
}

static void	lmt_redirection_init(t_lmt_redirection *p_redirection, int fd, char *path, int type)
{
	p_redirection->fd = fd;
	p_redirection->path = path;
	p_redirection->type = type;
}

t_lmt_redirection	*lmt_redirection_new(int fd, char *path, int type, int fd2)
{
	t_lmt_redirection	*p_redirection;

	p_redirection = lmt_redirection_alloc();
	lmt_redirection_init(p_redirection, fd, path, type);
	p_redirection->fd2 = fd2;
	return (p_redirection);
}

void	lmt_redirection_free(t_lmt_redirection *p_redirection, int option)
{
	//	path 는 어디서 free 하는가?
	if (option == REDIRECTION_FREE_FD)
		close(p_redirection->fd);
	free(p_redirection);
}

void	lmt_redirection_apply(t_lmt_redirection *p_redirection)
{
	int	fd;

	if (p_redirection->path != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			fd = open(p_redirection->path, O_RDONLY);
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd = -1;
		}
		if (fd == -1)
			lmt_exit(-1, NULL);
		dup2(fd, p_redirection->fd2);
		close(fd);
	}
	else
	{
		dup2(p_redirection->fd, p_redirection->fd2);
		close(p_redirection->fd);
	}
}

int	lmt_redirection_backup(t_lmt_redirection *p_redirection)
{
	int	duplicated_fd;
	int	fd;

	if (p_redirection->path != NULL)
	{
		if (p_redirection->type == TYPE_REDIRECTION_IN)
			fd = open(p_redirection->path, O_WRONLY | O_CREAT | O_TRUNC);
		else if (p_redirection->type == TYPE_REDIRECTION_OUT)
			fd = open(p_redirection->path, O_RDONLY);
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd = -1;
		}
		if (fd == -1)
			lmt_exit(-1, NULL);
		duplicated_fd = dup(p_redirection->fd2);
		dup2(fd, p_redirection->fd2);
		close(fd);
	}
	else
	{
		duplicated_fd = dup(p_redirection->fd2);
		dup2(p_redirection->fd, p_redirection->fd2);
		close(p_redirection->fd);
	}
	return (duplicated_fd);
}

t_lmt_redirection	*lmt_redirection_new_by_string_array(t_lmt_string_array *array)
{
	int	fd;
	char	*path;
	int	type;
	int	fd2;
	t_lmt_redirection	*p_redirection;
	int	return_value;

	if (array->count == 2)
	{
		fd = -1;
		if (**array->array == '<')
		{
			fd2 = FD_IN;
			type = TYPE_REDIRECTION_IN;
		}
		else if (**array->array == '>')
		{
			fd2 = FD_OUT;
			type = TYPE_REDIRECTION_OUT;
		}
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd = -1;
			path = NULL;
			type = TYPE_NONE;
			fd2 = -1;
		}
		path = array->array[1];
	}
	else if (array->count == 3)
	{
		fd = -1;
		return_value = lmt_atoi(array->array[0], &fd2);
		if (return_value == PARSE_FAIL)
			lmt_exit(-1, LMT_WRONG_PATH);
		if (*array->array[1] == '<')
			type = TYPE_REDIRECTION_IN;
		else if (*array->array[1] == '>')
			type = TYPE_REDIRECTION_OUT;
		else
		{
			lmt_exit(-1, LMT_WRONG_PATH);
			fd = -1;
			path = NULL;
			type = TYPE_NONE;
			fd2 = -1;
		}
		path = array->array[1];
	}
	else
	{
		lmt_exit(-1, LMT_WRONG_PATH);
		fd = -1;
		path = NULL;
		type = TYPE_NONE;
		fd2 = -1;
	}
	p_redirection = lmt_redirection_new(fd, path, type, fd2);
	return (p_redirection);
}
