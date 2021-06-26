/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:50:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 23:59:03 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_push(t_stack *a, t_stack *b)
{
	t_node	*n_a;
	t_node	*n_b;

	if (!b->cur)
		return ;
	node_top(a);
	node_top(b);
	n_b = b->top->next;
	n_a = b->top;
	n_b->pre = NULL;
	n_a->pre = NULL;
	n_a->next = a->top;
	a->top->pre = n_a;
	a->top = n_a;
}

void	ft_push(t_stack *stk_a, t_stack *stk_b, int sep)
{
	if (sep == PA)
		process_push(stk_a, stk_b);
	if (sep == PB)
		process_push(stk_b, stk_a);
}
