/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:02:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:59:43 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pvot_init(t_stack *stk, int size)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;

	stk->ptr = stk->top;
	arr = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		arr[i] = stk->ptr->data;
		if (stk->ptr->next)
			stk->ptr = stk->ptr->next;
	}
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
	tmp = arr[!(i % 2) ? i / 2 - 1 : i / 2];
	free(arr);
	return (tmp);
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int i;
	int pvot;
	int	rb;
	int pa;

	if (size == 1)
	{
		push_swap_init(stk_a, stk_b, ps, PA);
		return ;
	}
	rb = 0;
	pa = 0;
	i = -1;
	stk_b->ptr = stk_b->top;
	stk_a->ptr = stk_a->size ? stk_a->top : NULL;
	pvot = pvot_init(stk_b, size);
	stk_b->ptr = stk_b->top;
	while (++i < size)
	{
		if (stk_b->ptr->data <= pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RB);
			rb++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PA);
			pa++;
		}
	}
	i = -1;
	while (++i < rb)
		push_swap_init(stk_a, stk_b, ps, RRB);
	valid_init(stk_a, stk_b, ps);
	a_to_b(stk_a, stk_b, ps, pa);
	b_to_a(stk_a, stk_b, ps, rb);
}

void	a_to_b(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int i;
	int	pvot;
	int	ra;
	int	pb;

	if (size == 1)
		return ;
	ra = 0;
	pb = 0;
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->size ? stk_b->top : NULL;
	pvot = pvot_init(stk_a, size);
	stk_a->ptr = stk_a->top;
	i = -1;
	while (++i < size)
	{
		if (stk_a->ptr->data > pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RA);
			ra++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PB);
			pb++;
		}
	}
	i = -1;
	while (++i < ra)
		push_swap_init(stk_a, stk_b, ps, RRA);
	valid_init(stk_a, stk_b, ps);
	a_to_b(stk_a, stk_b, ps, ra);
	b_to_a(stk_a, stk_b, ps, pb);
}

void	sort_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	if (!valid_init(stk_a, stk_b, ps))
		a_to_b(stk_a, stk_b, ps, stk_a->size);
	print_finish(stk_a, stk_b, ps);
}
