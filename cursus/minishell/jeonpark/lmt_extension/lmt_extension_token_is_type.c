/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:04:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/10 12:40:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

int	lmt_is_token_type_control_operator(t_token *token)
{
	if (token == NULL)
		return (FALSE);
	return (is_type_control_operator(token->type));
}

int	lmt_is_token_type_redirection(t_token *token)
{
	if (token == NULL)
		return (FALSE);
	return (is_type_redirection(token->type));
}

int	lmt_is_token_type_open_parenthesis(t_token *token)
{
	if (token == NULL)
		return (FALSE);
	return (is_type_open_parenthesis(token->type));
}

int	lmt_is_token_type_close_parenthesis(t_token *token)
{
	if (token == NULL)
		return (FALSE);
	return (is_type_close_parenthesis(token->type));
}

int	lmt_is_token_type_command(t_token *token)
{
	if (token == NULL)
		return (FALSE);
	return (is_type_command(token->type));
}
