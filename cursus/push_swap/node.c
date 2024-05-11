/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:18:44 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:41:44 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_top(t_stack *stk)
{
	int		i;

	i = stk->size;
	while (stk->ptr->pre && i > 0)
	{
		if (stk->ptr->pre)
			stk->ptr = stk->ptr->pre;
		i--;
	}
	return (stk->ptr);
}

t_node	*node_bottom(t_stack *stk)
{
	int	i;

	i = stk->size;
	while (stk->ptr->next && i > 0)
	{
		stk->ptr = stk->ptr->next;
		i--;
	}
	return (stk->ptr);
}

void	node_push(t_stack *stk, char *str)
{
	t_node	*node;
	t_node	*old;

	node = node_init(str);
	if (stk->ptr == NULL)
		stk->ptr = node;
	else
	{
		old = stk->ptr;
		old->next = node;
		node->pre = old;
		stk->ptr = node;
	}
	stk->size++;
}

void	node_pop_top(t_stack *stk)
{
	t_node *cur_top;
	t_node *new_top;

	stk->ptr = stk->top;
	cur_top = stk->ptr;
	if (!stk->ptr || !stk->top)
		return ;
	else if (stk->size > 1)
	{
		new_top = stk->ptr->next;
		new_top->pre = NULL;
		stk->top = new_top;
	}
	stk->size--;
	stk->ptr = stk->top;
	free(cur_top);
}

void	node_pop_bottom(t_stack *stk)
{
	t_node *cur_bot;
	t_node *new_bot;

	stk->ptr = stk->bot;
	cur_bot = stk->ptr;
	if (!stk->ptr || !stk->bot)
		return ;
	else
	{
		new_bot = stk->ptr->pre;
		new_bot->next = NULL;
		stk->bot = new_bot;
	}
	stk->size--;
	stk->ptr = stk->bot;
	free(cur_bot);
}
