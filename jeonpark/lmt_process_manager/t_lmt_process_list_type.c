/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 20:09:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_list.h"
#include "t_lmt_process.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_process_list	*lmt_process_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process_list)));
}

static void	lmt_process_list_init(t_lmt_process_list *list)
{
	list->p_dummy = lmt_process_new(-1);
	list->last = list->p_dummy;
	list->redirection_to_close_list = lmt_redirection_list_new();
}

t_lmt_process_list	*lmt_process_list_new(void)
{
	t_lmt_process_list	*list;

	list = lmt_process_list_alloc();
	lmt_process_list_init(list);
	return (list);
}

void	lmt_process_list_free(t_lmt_process_list *list)
{
	t_lmt_process	*iterator;
	t_lmt_process	*next;

	iterator = list->p_dummy;
	next = iterator->next;
	while (iterator != NULL)
	{
		lmt_process_free(iterator);
		iterator = next;
		next = iterator->next;
	}
	lmt_redirection_list_free(p_proman->redirection_to_close_list, REDIRECTION_FREE_FD);
	free(list);
}
