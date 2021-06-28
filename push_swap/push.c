/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:50:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:53:03 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_push(t_stack *a, t_stack *b)
{
	t_node	*n_a;
	t_node	*n_b;
	int		i;

	i = -1;
	b->ptr = b->top;
	n_b = NULL;
	if (!b->size)
		return ;
	else if (b->size > 1)
		n_b = b->ptr->next;
	n_a = b->top;
	if (a->size > 0)
		a->top->pre = n_a;
	n_a->next = a->ptr ? a->ptr : NULL;
	a->top = n_a;
	b->top = n_b;
	b->ptr = b->top;
	a->ptr = a->top;
	a->ptr->pre = NULL;
	if (n_b)
		b->top->pre = NULL;
	a->size++;
	b->size--;
	if (a->size > 0 && !a->bot)
	{
		while (++i < a->size)
			if (a->ptr->next)
				a->ptr = a->ptr->next;
		a->bot = a->ptr;
	}
	a->ptr = a->top;
}

void	ft_push(t_stack *stk_a, t_stack *stk_b, int sep)
{
	if (sep == PA)
		process_push(stk_a, stk_b);
	if (sep == PB)
		process_push(stk_b, stk_a);
}
