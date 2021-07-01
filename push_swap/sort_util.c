/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:51:27 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/29 12:51:54 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pvot_util(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
	return (arr[!(i % 2) ? i / 2 - 1 : i / 2]);
}

void	sort_util_b(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int pvot;
	int i;

	i = -1;
	pvot = pvot_init(stk_b, size);
	stk_b->ptr = stk_b->top;
	stk_b->ptr = stk_b->top;
	while (++i < size)
	{
		if (stk_b->ptr->data <= pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RB);
			ps->rb++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PA);
			ps->pa++;
		}
	}
	i = -1;
	while (++i < ps->rb)
		push_swap_init(stk_a, stk_b, ps, RRB);
	valid_init(stk_a, stk_b, ps);
}

void	sort_util_a(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int pvot;
	int i;

	i = -1;
	pvot = pvot_init(stk_a, size);
	stk_a->ptr = stk_a->top;
	stk_a->ptr = stk_a->top;
	while (++i < size)
	{
		if (stk_a->ptr->data > pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RA);
			ps->ra++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PB);
			ps->pb++;
		}
	}
	i = -1;
	if (ps->flag)
		while (++i < ps->ra)
			push_swap_init(stk_a, stk_b, ps, RRA);
	valid_init(stk_a, stk_b, ps);
}
