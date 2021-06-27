/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:02:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 03:37:04 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pvot_init(t_stack *stk)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;

	stk->ptr = stk->top;
	arr = malloc(sizeof(int) * stk->size);
	i = -1;
	while (++i < stk->size)
	{
		arr[i] = stk->ptr->data;
		if (stk->ptr->next)
			stk->ptr = stk->ptr->next;
	}
	i = -1;
	while (++i < stk->size)
	{
		j = i;
		while (++j < stk->size)
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
	}
	tmp = arr[!(i % 2) ? i / 2 - 1 : i / 2];
	free(arr);
	return (tmp);
}

void	B_to_A(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int i;
	int pvot;

	if (size == 1)
	{
		push_swap_init(stk_a, stk_b, ps, PA);
		return ;
	}
	i = -1;
	ps->rb = 0;
	ps->pa = 0;
	stk_b->ptr = stk_b->top;
	stk_a->ptr = stk_a->size ? stk_a->top : NULL;
	pvot = pvot_init(stk_b);
	stk_b->ptr = stk_b->top;
	while (++i < size)
	{
		if (stk_b->ptr->data > pvot)
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
		push_swap_init(stk_a, stk_b, ps, RRA);
	valid_init(stk_a, stk_b, ps);
	A_to_B(stk_a, stk_b, ps, ps->pa);
	B_to_A(stk_a, stk_b, ps, ps->rb);
}

void	A_to_B(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int i;
	int	pvot;

	if (size == 1)
		return ;
	ps->ra = 0;
	ps->pb = 0;
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->size ? stk_b->top : NULL;
	pvot = pvot_init(stk_a);
	stk_a->ptr = stk_a->top;
	i = -1;
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
	while (++i < ps->ra)
		push_swap_init(stk_a, stk_b, ps, RRA);
	valid_init(stk_a, stk_b, ps);
	A_to_B(stk_a, stk_b, ps, ps->ra);
	B_to_A(stk_a, stk_b, ps, ps->pb);
}

void	sort_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	valid_init(stk_a, stk_b, ps);
	A_to_B(stk_a, stk_b, ps, stk_a->size);
	//push_swap_init(stk_a, stk_b, ps, SB);
	//push_swap_init(stk_a, stk_b, ps, PA);
	//push_swap_init(stk_a, stk_b, ps, PA);
	print_finish(stk_a, stk_b, ps);
}
