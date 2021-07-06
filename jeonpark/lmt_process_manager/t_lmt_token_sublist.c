/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 19:20:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_token_sublist.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_token_sublist	*lmt_token_sublist_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_token_sublist)));
}

static void	lmt_token_sublist_init(t_lmt_token_sublist *sublist, t_lmt_token *first, t_lmt_token *last)
{
	sublist->first = first;
	sublist->last = last;

}

t_lmt_token_sublist	*lmt_token_sublist_new(t_lmt_token *first, t_lmt_token *last)
{
	t_lmt_token_sublist	*sublist;

	sublist = lmt_token_sublist_alloc();
	lmt_token_sublist_init(sublist, first, last);
	return (sublist);
}

void	lmt_token_sublist_free(t_lmt_token_sublist *sublist)
{
	free(sublist);
}
