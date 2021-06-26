/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:03:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 23:15:31 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_rotate(t_stack *stk, t_stack *ps)
{
	t_node	*new_top;
	t_node	*old_top;

	node_bottom(stk);
	old_top = stk->top;
	node_top(stk);
	new_top = stk->top->next;
	new_top->pre = NULL;
	stk->top->next = NULL;
	old_top->next = stk->top;
	stk->top->pre = old_top;
	stk->top = new_top;
}

void	ft_rotate(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == RA || (sep == RR && ps->size == RB))
		process_rotate(stk_a, ps);
	else if (sep == RB || (sep == RR && ps->size == RA))
		process_rotate(stk_b, ps);
}
