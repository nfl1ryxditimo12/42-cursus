/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/17 12:21:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_token_sublist.h"
#include "lmt_util.h"
#include "minishell.h"

//	stdlib.h: free()

static t_lmt_token_sublist	*lmt_token_sublist_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token_sublist)));
}

static void	lmt_token_sublist_init(t_lmt_token_sublist *sublist, t_token *first, t_token *terminator)
{
	sublist->first = first;
	sublist->terminator = terminator;
}

t_lmt_token_sublist	*lmt_token_sublist_new(t_token *first, t_token *terminator)
{
	t_lmt_token_sublist	*sublist;

	sublist = lmt_token_sublist_alloc();
	lmt_token_sublist_init(sublist, first, terminator);
	return (sublist);
}

void	lmt_token_sublist_free(t_lmt_token_sublist *sublist)
{
	free(sublist);
}
