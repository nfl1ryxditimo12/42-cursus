/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:50:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:02:34 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_push(t_stack *stk_a, t_stack *stk_b)
{
	t_stack *a;
	t_stack *b;
	t_stack *ptr;

	a = stk_a;
	b = stk_b;
	node_front(a);
	node_front(b);
	if (!b->top->data)
		return ;
	a->top->pre = create_node(0);
	a->top->pre->data = b->top->data;
	ptr = b->top->next;
	free(b->top);
	ptr->pre = NULL;
}

void	ft_push(t_stack *stk_a, t_stack *stk_b, int sep)
{
	if (sep == 4)
		process_push(stk_a, stk_b);
	if (sep == 5)
		process_push(stk_b, stk_a);
}
