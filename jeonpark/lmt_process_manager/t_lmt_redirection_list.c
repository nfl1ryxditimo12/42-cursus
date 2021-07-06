/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 18:44:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_redirection_list.h"
#include "t_lmt_redirection.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_redirection	*lmt_redirection_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_redirection_list)));
}

static void	lmt_redirection_list_init(t_lmt_redirection_list *list)
{
	list->p_dummy = lmt_redirection_new(TYPE_LIST_DUMMY, -1, NULL, -1);
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

void	lmt_redirection_list_append(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection)
{
	list->last->next = p_redirection;
	p_redirection->next = NULL;
	list->last = p_redirection;
}

void	lmt_redirection_list_apply(t_lmt_redirection_list *list)
{
	t_lmt_redirection	*iterator;
	int	fd;

	iterator = p_process->p_dummy->next;
	while (iterator != NULL)
	{
		lmt_redirection_appy(iterator);
		iterator = iterator->next;
	}
}
