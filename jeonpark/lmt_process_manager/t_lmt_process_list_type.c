/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 20:00:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"
#include "lmt_c_library.h"
#include "constant.h"

//	stdlib.h: free(), NULL

static t_lmt_process_list	*lmt_process_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process_list)));
}

static void	lmt_process_list_init(t_lmt_process_list *list)
{
	t_lmt_process	*p_dummy;

	p_dummy = lmt_process_new(TYPE_TERMINATOR, NULL);
	p_dummy->prev = NULL;
	p_dummy->next = NULL;
	list->p_dummy = p_dummy;
	list->last = p_dummy;
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
	free(list);
}
