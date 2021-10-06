/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_tokenize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:04:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 19:17:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

int	lmt_is_token_type_control_operator(t_token *p_token)
{
	if (p_token == NULL)
		return (FALSE);
	return (is_type_control_operator(p_token->type));
}

int	lmt_is_token_type_redirection(t_token *p_token)
{
	if (p_token == NULL)
		return (FALSE);
	return (is_type_redirection(p_token->type));
}

int	lmt_is_token_type_open_parenthesis(t_token *p_token)
{
	if (p_token == NULL)
		return (FALSE);
	return (is_type_open_parenthesis(p_token->type));
}

int	lmt_is_token_type_close_parenthesis(t_token *p_token)
{
	if (p_token == NULL)
		return (FALSE);
	return (is_type_close_parenthesis(p_token->type));
}

int	lmt_is_token_type_command(t_token *p_token)
{
	if (p_token == NULL)
		return (FALSE);
	return (is_type_command(p_token->type));
}
