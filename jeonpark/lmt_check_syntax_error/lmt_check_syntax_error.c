/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_syntax_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:10:01 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 10:52:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_check_syntax_error.h"

static int	check_syntax_error_to_element(t_token *element)
{
	if (lmt_is_token_type_open_parenthesis(element))
	{
		if (!(lmt_is_token_type_control_operator(element->pre)
					|| lmt_is_token_type_open_parenthesis(element->pre)))
			return (PARSE_FAILURE);
	}
	else if (lmt_is_token_type_close_parenthesis(element))
	{
		if (lmt_is_token_type_open_parenthesis(element->pre)
				|| !(lmt_is_token_type_control_operator(element->next)
					|| lmt_is_token_type_close_parenthesis(element->next)
					|| element->next == NULL))
			return (PARSE_FAILURE);
	}
	else if (lmt_is_token_type_control_operator(element))
	{
		if (lmt_is_token_type_open_parenthesis(element->pre)
				|| lmt_is_token_type_close_parenthesis(element->next)
				|| lmt_is_token_type_control_operator(element->next)
				|| element->next == NULL)
			return (PARSE_FAILURE);
	}
	else if (lmt_is_token_type_redirection(element))
	{
		if (!lmt_is_token_type_command(element->next))
			return (PARSE_FAILURE);
	}
	return (PARSE_SUCCESS);
}

int	lmt_check_syntax_error(t_token *first_token)
{
	t_token	*element;
	int		return_value;

	element = first_token;
	if (lmt_is_token_type_control_operator(first_token))
		return (PARSE_FAILURE);
	element = element->next;
	while (element != NULL)
	{
		return_value = check_syntax_error_to_element(element);
		if (return_value == PARSE_FAILURE)
			return (PARSE_FAILURE);
		element = element->next;
	}
	return (PARSE_SUCCESS);
}
