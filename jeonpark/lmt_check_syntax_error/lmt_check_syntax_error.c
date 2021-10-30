/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_syntax_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:10:01 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 21:50:00 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_check_syntax_error.h"

static int	is_error_open_parenthesis(t_token *element)
{
	return (!(lmt_is_token_type_control_operator(element->pre)
			|| lmt_is_token_type_open_parenthesis(element->pre)));
}

static int	is_error_close_parenthesis(t_token *element)
{
	return (lmt_is_token_type_open_parenthesis(element->pre)
		|| !(lmt_is_token_type_control_operator(element->next)
			|| lmt_is_token_type_close_parenthesis(element->next)
			|| element->next == NULL));
}

static int	is_error_control_operator(t_token *element)
{
	return (lmt_is_token_type_open_parenthesis(element->pre)
		|| lmt_is_token_type_close_parenthesis(element->next)
		|| lmt_is_token_type_control_operator(element->next)
		|| element->next == NULL);
}

static int	check_syntax_error_to_element(t_token *element)
{
	if (lmt_is_token_type_open_parenthesis(element))
	{
		if (is_error_open_parenthesis(element))
			return (PARSE_FAILURE);
	}
	else if (lmt_is_token_type_close_parenthesis(element))
	{
		if (is_error_close_parenthesis(element))
			return (PARSE_FAILURE);
	}
	else if (lmt_is_token_type_control_operator(element))
	{
		if (is_error_control_operator(element))
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
