/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:18:44 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:52:50 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_front(t_stack *stk)
{
	while (stk->top->pre)
		stk->top = stk->top->pre;
}

void	node_back(t_stack *stk)
{
	while (stk->top->next)
		stk->top = stk->top->next;
}

void	node_push(t_stack *stk, char *str)
{
	t_node	*node;
	t_node	*old;

	node = create_node(str);
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

void	node_pop_front(t_stack *stk)
{
	t_node *cur_top;
	t_node *new_top;

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

void	node_pop_back(t_stach *stk)
{
	t_node *cur_top;
	t_node *new_top;

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
