/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:18:44 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 23:27:07 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_top(t_stack *stk)
{
	int i;

	i = stk->size;
	while (stk->top->pre && i > 0)
	{
		stk->top = stk->top->pre;
		i--;
	}
}

void	node_bottom(t_stack *stk)
{
	int	i;

	i = stk->cur;
	while (stk->top->next && i > 0)
	{
		stk->top = stk->top->next;
		i--;
	}
}

void	node_push(t_stack *stk, char *str)
{
	t_node	*node;
	t_node	*old;

	node = node_init(str);
	if (stk->top == NULL)
		stk->top = node;
	else
	{
		old = stk->top;
		old->next = node;
		node->pre = old;
		stk->top = node;
	}
	stk->size++;
}

void	node_pop_top(t_stack *stk)
{
	t_node *cur_top;
	t_node *new_top;

	node_top(stk);
	cur_top = stk->top;
	if (!cur_top)
		return ;
	else
	{
		new_top = stk->top->next;
		new_top->pre = NULL;
		stk->top = new_top;
	}
	stk->size--;
	free(cur_top);
}

void	node_pop_bottom(t_stack *stk)
{
	t_node *cur_top;
	t_node *new_top;

	node_bottom(stk);
	cur_top = stk->top;
	if (!cur_top)
		return ;
	else
	{
		new_top = stk->top->pre;
		new_top->next = NULL;
		stk->top = new_top;
	}
	stk->size--;
	free(cur_top);
}
