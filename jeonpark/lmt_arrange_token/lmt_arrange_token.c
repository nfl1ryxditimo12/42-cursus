/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_arrange_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:15:10 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 19:49:21 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_arrange_token.h"

static void	get_redirection_target_name(t_token *element)
{
	char	**source;
	char	**target;
	char	**ptr;

	target = element->token + 1;
	source = element->next->token;
	ptr = source + 1;
	*target = *source;
	while (*ptr != NULL)
	{
		*(ptr - 1) = *ptr;
		++ptr;
	}
}

static void	move_token_first(t_token **pp_first_token, t_token *element)
{
	element->pre->next = element->next;
	if (element->next != NULL)
		element->next->pre = element->pre;
	if (element->pre != NULL)
		element->pre->next = element;
	(*pp_first_token)->pre = element;
	element->pre = (*pp_first_token)->pre;
	element->next = *pp_first_token;
	*pp_first_token = element;
}

static void	move_token_contents_to_command_token(t_token *p_first_token, t_token *element)
{
	char	**target;
	char	**source;

	target = p_first_token->token;
	source = element->token;
	while (*target != NULL)
		++target;
	while (*source != NULL)
	{
		*target = *source;
		*source = NULL;
		++target;
		++source;
	}
}

static void	lmt_arrange_token_element(t_token **pp_first_token, t_token *element)
{
	if (lmt_is_token_type_redirection(element))
		get_redirection_target_name(element);
	if (lmt_is_token_type_command(element) && element->token[0] != NULL)
	{
		if (lmt_is_token_type_redirection(*pp_first_token))
			move_token_first(pp_first_token, element);
		else
			move_token_contents_to_command_token(*pp_first_token, element);
	}
}

void	lmt_arrange_token(t_token *p_first_token)
{
	t_token	*element;

	element = p_first_token;
	while (element != NULL)
	{
		if (lmt_is_token_type_command(element) || lmt_is_token_type_redirection(element))
			lmt_arrange_token_element(&p_first_token, element);
		else
			p_first_token = element->next;
		element = element->next;
	}
}
