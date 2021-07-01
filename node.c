/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:12:54 by seonkim           #+#    #+#             */
/*   Updated: 2021/07/01 19:01:24 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*node_init(void)
{
	t_token	*node;

	if (!(node = malloc(sizeof(t_token))))
		print_err(MEM_ERR, 0);
	node->token = 0;
	node->pre = NULL;
	node->next = NULL;
	return (node);
}

void	node_push(t_handler *hand, int index)
{
    t_token *new;
	t_token	*old;

	new = node_init();
	if (hand->line == NULL)
		hand->line = new;
	else
	{
		old = hand->line;
		old->next = new;
		new->pre = old;
		hand->line = new;
	}
    hand->line->type = 0;
    hand->line->index = index;
}