/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 21:23:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_token_list.h"
#include "t_lmt_token.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_token_list	*lmt_token_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token_list)));
}

static void	lmt_token_list_init(t_lmt_token_list *list)
{
	list->p_dummy = lmt_token_new(TYPE_LIST_DUMMY);
	list->last = list->p_dummy;
	list->last->next = lmt_token_new(TYPE_NONE);
	lsit->last->next->next = NULL;
}

t_lmt_token_list	*lmt_token_list_new(void)
{
	t_lmt_token_list	*list;

	list = lmt_token_list_alloc();
	lmt_token_list_init(list);
	return (list);
}

void	lmt_token_list_free(t_lmt_token_list *list)
{
	t_lmt_token	*iterator;
	t_lmt_token	*next;

	iterator = list->p_dummy;
	next = iterator->next;
	while (iterator != NULL)
	{
		lmt_token_free(iterator);
		iterator = next;
		next = iterator->next;
	}
	free(list);
}
