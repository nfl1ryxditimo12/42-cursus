/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list_type.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/09 15:56:07 by jeonpark         ###   ########.fr       */
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
