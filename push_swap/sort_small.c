/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:39:17 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:50:49 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_size(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int i;
	int pvot;
	int	size;

	i = -1;
	pvot = pvot_init(stk_a, stk_a->size);
	stk_a->ptr = stk_a->top;
	size = stk_a->size;
	while (++i < size)
	{
		if (stk_a->ptr->data > pvot && stk_a->ptr->data != stk_a->bot->data)
			push_swap_init(stk_a, stk_b, ps, RA);
		else if (stk_a->ptr->data <= pvot)
			push_swap_init(stk_a, stk_b, ps, PB);
	}
	if (stk_a->top->data > stk_a->top->next->data)
		push_swap_init(stk_a, stk_b, ps, RA);
	pvot = pvot_init(stk_b, stk_b->size);
	i = -1;
	size = stk_b->size;
	stk_b->ptr = stk_b->top;
	while (++i < size)
	{
		if (stk_b->ptr->data > pvot)
		{
			push_swap_init(stk_a, stk_b, ps, PA);
			break ;
		}
		else
			push_swap_init(stk_a, stk_b, ps, RB);
	}
	if (stk_b->size > 1 && stk_b->top->data < stk_b->top->next->data)
		push_swap_init(stk_a, stk_b, ps, RB);
	push_swap_init(stk_a, stk_b, ps, PA);
	push_swap_init(stk_a, stk_b, ps, PA);
}

void	three_size(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	t_node	*next;
	int		pvot;

	pvot = pvot_init(stk_a, 3);
	stk_a->ptr = stk_a->top;
	next = stk_a->ptr->next;
	if (stk_a->ptr->data < next->data && next->data > pvot &&
			next->next->data == pvot)
	{
		push_swap_init(stk_a, stk_b, ps, PB);
		push_swap_init(stk_a, stk_b, ps, SA);
		push_swap_init(stk_a, stk_b, ps, PA);
	}
	else if (next->data < pvot && next->data < next->next->data &&
			stk_a->ptr->data == pvot)
		push_swap_init(stk_a, stk_b, ps, SA);
	else if (next->data > pvot && next->data > next->next->data)
		push_swap_init(stk_a, stk_b, ps, RRA);
	else if (stk_a->ptr->data > next->data && next->next->data < pvot)
	{
		push_swap_init(stk_a, stk_b, ps, SA);
		push_swap_init(stk_a, stk_b, ps, RRA);
	}
	else if (stk_a->ptr->data > next->data && stk_a->ptr->data > pvot)
		push_swap_init(stk_a, stk_b, ps, RA);
}

void	small_arg(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	stk_a->ptr = stk_a->top;
	if (stk_a->size == 1)
		print_finish(stk_a, stk_b, ps);
	if (valid_check1(stk_a))
		print_finish(stk_a, stk_b, ps);
	stk_a->ptr = stk_a->top;
	if (valid_check2(stk_a) && stk_a->size == 2)
		push_swap_init(stk_a, stk_b, ps, SA);
	else if (stk_a->size == 3)
		three_size(stk_a, stk_b, ps);
	else if (stk_a->size == 5 || stk_a->size == 4)
		five_size(stk_a, stk_b, ps);
	print_finish(stk_a, stk_b, ps);
}
