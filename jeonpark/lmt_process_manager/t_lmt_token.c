/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:54:15 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 18:12:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_token.h"
#include "lmt_util.h"

static t_lmt_token	*lmt_token_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token)));
}

static void	lmt_token_init(t_lmt_token *p_token, int type, char *string)
{
	p_token->type = type;
	p_token->string = string;
}

t_lmt_token	*lmt_token_new(int type, char *string)
{
	t_lmt_token	*p_token;

	p_token = lmt_token_alloc();
	lmt_token_init(p_tokentype, string);
	return (p_token);
}

void	lmt_token_free(t_lmt_token *p_token)
{
	free(p_token);
}
