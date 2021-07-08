/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:05:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"

//	stdlib.h: free()

static t_lmt_redirection_list	*lmt_redirection_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection_list)));
}

static void	lmt_redirection_list_init(t_lmt_redirection_list *list)
{
	list->p_dummy = lmt_redirection_new(TYPE_NONE, NULL, -1, -1);
	list->last = list->p_dummy;
}

t_lmt_redirection_list	*lmt_redirection_list_new(void)
{
	t_lmt_redirection_list	*list;

	list = lmt_redirection_list_alloc();
	lmt_redirection_list_init(list);
	return (list);
}

void	lmt_redirection_list_free(t_lmt_redirection_list *list, int option)
{
	t_lmt_redirection	*iterator;
	t_lmt_redirection	*next;

	iterator = list->p_dummy;
	next = iterator->next;
	while (iterator != NULL)
	{
		lmt_redirection_free(iterator, option);
		iterator = next;
		next = iterator->next;
	}
	free(list);
}

void	lmt_redirection_list_push(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection)
{
	p_redirection->next = list->p_dummy->next;
	list->p_dummy->next = p_redirection;
	if (list->last == list->p_dummy)
		list->last = p_redirection;
}

void	lmt_redirection_list_append(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection)
{
	list->last->next = p_redirection;
	p_redirection->next = NULL;
	list->last = p_redirection;
}

void	lmt_redirection_list_apply(t_lmt_redirection_list *list)
{
	t_lmt_redirection	*iterator;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		lmt_redirection_apply(iterator);
		iterator = iterator->next;
	}
}

t_lmt_redirection_list	*lmt_redirection_list_backup(t_lmt_redirection_list *list)
{
	t_lmt_redirection		*iterator;
	int						fd;
	t_lmt_redirection		*p_element;
	t_lmt_redirection_list	*ret_list;

	ret_list = lmt_redirection_list_new();
	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		fd = lmt_redirection_backup(iterator);
		p_element = lmt_redirection_new(fd, NULL, -1, iterator->fd2);
		lmt_redirection_list_push(ret_list, p_element);
		iterator = iterator->next;
	}
	return (ret_list);
}

void	lmt_redirection_list_backdown(t_lmt_redirection_list *list)
{
	lmt_redirection_list_apply(list);
	lmt_redirection_list_free(list, REDIRECTION_FREE_NORMAL);
}
