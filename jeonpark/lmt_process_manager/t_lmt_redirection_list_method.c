/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list_method.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/14 12:56:52 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_lmt_process_manager.h"

//	stddef.h: NULL

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

///	Applies parameter 'list' and returns a redirection list for undo
t_lmt_redirection_list	*lmt_redirection_list_backup(t_lmt_redirection_list *list)
{
	t_lmt_redirection		*iterator;
	int						fd_new;
	t_lmt_redirection		*p_element;
	t_lmt_redirection_list	*ret_list;

	ret_list = lmt_redirection_list_new();
	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		fd_new = lmt_redirection_backup(iterator);
		p_element = lmt_redirection_new(iterator->fd_old, -1, fd_new, NULL);
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
