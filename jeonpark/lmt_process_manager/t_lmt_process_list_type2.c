/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:57:37 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/25 13:47:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

static int	is_token_end_of_process(t_token *element)
{
	int	return_value;

	return_value = (element == NULL);
	return_value |= lmt_is_token_type_control_operator(element);
	return (return_value);
}

static t_token	*append_new_parenthesis_process_by_token(
		t_lmt_process *list, t_token *element)
{
	int					parenthesis_count;
	t_token				*new_process_first_token;
	t_lmt_token_sublist	*new_token_sublist;
	t_lmt_process		*new_process;

	parenthesis_count = 1;
	new_process_first_token = element->next;
	element = new_process_first_token;
	while (parenthesis_count > 0)
	{
		if (lmt_is_token_type_open_parenthesis(element))
			++parenthesis_count;
		else if (lmt_is_token_type_close_parenthesis(element))
			--parenthesis_count;
		element = element->next;
	}
	new_token_sublist = lmt_token_sublist_new(new_process_first_token, element);
	new_process = lmt_process_new(TYPE_PROCESS_PARENTHESIS, new_token_sublist);
	lmt_process_list_append(list, new_process);
	new_process->list = lmt_process_list_new_by_token_sublist(new_process->token_sublist);
	new_process->list->list = new_process;
	return (element);
}

static t_token	*append_new_process_by_token(
		t_lmt_process *list, t_token *element)
{
	t_token				*new_process_first_token;
	t_lmt_token_sublist	*new_token_sublist;
	t_lmt_process		*new_process;

	new_process_first_token = element;
	while (!is_token_end_of_process(element))
		element = element->next;
	new_token_sublist = lmt_token_sublist_new(new_process_first_token, element);
	new_process = lmt_process_new(TYPE_PROCESS_NORMAL, new_token_sublist);
	lmt_process_list_append(list, new_process);
	return (element);
}

t_lmt_process	*lmt_process_list_new_by_token_sublist(t_lmt_token_sublist *token_sublist)
{
	t_lmt_process	*new_process_list;
	t_token			*element;

	new_process_list = lmt_process_list_new();
	element = token_sublist->first;
	while (!(element == token_sublist->terminator || element == NULL))
	{
		if (lmt_is_token_type_open_parenthesis(element))
			element = append_new_parenthesis_process_by_token(new_process_list, element);
		else if (lmt_is_token_type_command(element))
			element = append_new_process_by_token(new_process_list, element);
		else
			element = element->next;
	}
	return (new_process_list);
}
