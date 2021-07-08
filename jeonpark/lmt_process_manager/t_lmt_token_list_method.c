/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list_method.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:23:55 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_lmt_process_manager.h"

//	stddef.h: NULL

void	lmt_token_list_append(t_lmt_token_list *list, t_lmt_token *p_element)
{
	p_element->next = list->last->next;
	list->last->next = p_element;
	list->last = p_element;
}

//	Return new lmt_token_list by t_token
t_lmt_token_list	*lmt_token_list_new_by_token(t_token *p_token)
{
	t_lmt_token_list	*list;

	(void)p_token;
	list = lmt_token_list_new();
	return (list);
///	compose this code...
//
//	lmt_token_list	*list;
//	t_token	*iterator;
//	t_token	*previous;
//
//	list = lmt_token_list_new();
//	iterator = p_token;
//	lmt_token_list_append(list, type, string);
//	//first();
//	previous = iterator;
//	iterator = previous->next;
//	while (iterator != NULL)
//	{
//		if (**iterator->token == '|')
//			return (SYNTAX_ERROR_PIPE);
//		lmt_process_list_append(p_proman->process_list, iterator->token, lmt_redirection_array_new());
//		iterator = iterator->next;
//		//	iterator 의 끝이 NULL 인가 아니면 갯수만큼 돌려야하는가?
//		if (iterator == NULL)
//			return (NORMAL);
//		iterator = iterator->next;
//		if (iterator == NULL)
//			return (SYNTAX_ERROR_PIPE);
//	}
}
