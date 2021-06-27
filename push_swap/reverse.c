/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:47:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/27 22:00:40 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_reverse2(t_stack *stk)
{
	t_node	*new_top;
	t_node	*old_top;

	node_top(stk);
	old_top = stk->top;
	node_bottom(stk);
	new_top = stk->top;
	new_top->next = old_top;
	old_top->pre = new_top;
	new_top->pre = NULL;
	stk->top = new_top;
}

void	process_reverse(t_stack *stk)
{
	t_node	*new_ptr;
	t_node	*bot_ptr;

	if (stk->size < 2)
		return ;
	bot_ptr = stk->bot->pre;
	new_ptr = stk->bot;
	new_ptr->next = stk->top;
	stk->top->pre = new_ptr;
	stk->top = new_ptr;
	stk->bot = bot_ptr;
	stk->ptr = stk->top;
	stk->top->pre = NULL;
	stk->bot->next = NULL;
}

void	ft_reverse(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == RRA || (sep == RRR && ps->cur == RRB))
		process_reverse(stk_a);
	else if (sep == RRB || (sep == RRR && ps->cur == RRA))
		process_reverse(stk_b);
}
