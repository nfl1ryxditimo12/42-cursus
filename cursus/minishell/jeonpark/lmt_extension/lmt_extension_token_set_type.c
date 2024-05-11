/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_extension_token_set_type.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:34:00 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 19:32:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

static int	get_token_type(const char *token_0)
{
	if (token_0 == NULL)
		return (TYPE_UNDEFINED);
	else if (lmt_str_equals(token_0, "<"))
		return (TYPE_REDIRECTION_IN);
	else if (lmt_str_equals(token_0, "<<"))
		return (TYPE_REDIRECTION_WORD);
	else if (lmt_str_equals(token_0, ">"))
		return (TYPE_REDIRECTION_OUT);
	else if (lmt_str_equals(token_0, ">>"))
		return (TYPE_REDIRECTION_APPEND);
	else if (lmt_str_equals(token_0, "|"))
		return (TYPE_CONTROL_OPERATOR_PIPE);
	else if (lmt_str_equals(token_0, "&&"))
		return (TYPE_CONTROL_OPERATOR_AND);
	else if (lmt_str_equals(token_0, "||"))
		return (TYPE_CONTROL_OPERATOR_OR);
	else if (lmt_str_equals(token_0, "("))
		return (TYPE_OPEN_PARENTHESIS);
	else if (lmt_str_equals(token_0, ")"))
		return (TYPE_CLOSE_PARENTHESIS);
	return (TYPE_COMMAND);
}

void	lmt_set_token_type(t_token *first_token)
{
	t_token	*element;

	element = first_token;
	while (element != NULL)
	{
		element->type = get_token_type(element->token[0]);
		element = element->next;
	}
}
