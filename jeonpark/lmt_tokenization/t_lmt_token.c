/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:54:15 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/09 12:39:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"

//	stdlib.h: free(), NULL

static t_lmt_token	*lmt_token_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token)));
}

static void	lmt_token_init(t_lmt_token *p_token, int type)
{
	p_token->type = type;
	p_token->array = lmt_string_array_new();
}

t_lmt_token	*lmt_token_new(int type)
{
	t_lmt_token	*p_token;

	p_token = lmt_token_alloc();
	lmt_token_init(p_token, type);
	return (p_token);
}

void	lmt_token_free(t_lmt_token *p_token)
{
	lmt_string_array_free(p_token->array);
	free(p_token);
}

void	lmt_token_append_string(t_lmt_token *p_token, char *string)
{
	lmt_string_array_append(p_token->array, string);
}

void	lmt_token_append_token(t_lmt_token *lhs, t_lmt_token *rhs)
{
	lmt_string_array_append_array(lhs->array, rhs->array);
}
