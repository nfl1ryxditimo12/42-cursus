/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_token_arrange.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:15:10 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/10 14:06:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

static void	get_redirection_target_path(t_token *element)
{
	char	**source;
	char	**target;

	target = element->token + 1;
	source = element->next->token;
	*target = *source;
	while (*source != NULL)
	{
		*source = *(source + 1);
		++source;
	}
}

static void	append_token_to_first(t_token *first_token, t_token *element)
{
	char	**target;
	char	**source;

	target = first_token->token;
	while (*target != NULL)
		++target;
	source = element->token;
	while (*source != NULL)
	{
		*target = *source;
		*source = NULL;
		++target;
		++source;
	}
}

static void	arrange_token(t_handler *handler, t_token *element)
{
	if (lmt_is_token_type_redirection(element))
	{
		get_redirection_target_path(element);
		if (element == handler->line)
		{
			handler->line = lmt_remove_token(element->next);
			lmt_insert_token_first(element, handler->line);
		}
	}
	else if (lmt_is_token_type_command(element))
		append_token_to_first(handler->line, element);
	else
		handler->line = element->next;
}

static void	remove_all_empty_token(t_token *first_token)
{
	t_token	*element;
	t_token	*element_to_free;

	element = first_token;
	while (element != NULL)
	{
		if (element->token[0] == NULL)
		{
			element_to_free = element;
			element = element->next;
			lmt_remove_token(element_to_free);
			free(element_to_free);
			continue;
		}
		element = element->next;
	}
}

///	Used handler->line as address of command_token.
///	*Fix comment below*
///	If element's type is redirection:
///		Append element->next->token[0] to element->token.
///		And if element is first_element, move element->next to first.
///	If element's type is command:
///		Append element->token to first_element->token.
///		And free the empty element.
/// Else:
///		first_element = element->next;
void	lmt_arrange_token(t_handler *handler)
{
	t_token	*element;

	handler->line = handler->top;
	element = handler->top;
	if (lmt_is_token_type_redirection(element))
		handler->top = element->next;
	while (element != NULL)
	{
		arrange_token(handler, element);
		element = element->next;
	}
	remove_all_empty_token(handler->top);
}
