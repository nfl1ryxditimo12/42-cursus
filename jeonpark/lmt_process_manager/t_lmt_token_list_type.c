/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/06 11:02:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "t_lmt_token_list.h"
#include "t_lmt_token.h"
#include "lmt_util.h"

static t_lmt_token_list	*lmt_token_list_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token_list)));
}

static void	lmt_token_list_init(t_lmt_token_list *list)
{
	list->p_dummy = lmt_token_new(TYPE_LIST_DUMMY, NULL);
	list->last = list->p_dummy;
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
	while (iterator != NULL)
	{
		next = iterator->next;
		lmt_token_free(iterator);
		iterator = next;
	}
	free(list);
}
