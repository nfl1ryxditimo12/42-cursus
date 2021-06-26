/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:47:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 23:18:57 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_reverse(t_stack *stk)
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

void	ft_reverse(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == RRA || (sep == RRR && ps->size == RRB))
		process_reverse(stk_a);
	else if (sep == RRB || (sep == RRR && ps->size == RRA))
		process_reverse(stk_b);
}
