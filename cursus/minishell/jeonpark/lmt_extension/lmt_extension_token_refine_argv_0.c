/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_extension_token_set_argv_zero.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:14:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/26 17:17:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

///	If argv[0] is "<directory>/", returns "".
void	lmt_refine_token_argv_0(t_token *p_command_token)
{
	t_lmt_string	*string;
	char			*last_slash;

	string = lmt_string_new(p_command_token->token[0]);
	last_slash = lmt_unsafe_strrchr(string->value, "/");
	if (last_slash == NULL)
		return ;
	else
	{
		free(p_command_token->token[0]);
		p_command_token->token[0] = lmt_unsafe_strdup(last_slash + 1);
	}
	lmt_string_free(string);
}
