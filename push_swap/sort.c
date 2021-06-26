/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:02:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/27 00:04:22 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pvot_init(t_stack *stk)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;

	node_top(stk);
	arr = malloc(sizeof(int) * stk->size);
	i = -1;
	while (++i < stk->size)
	{
		arr[i] = stk->top->data;
		if (stk->top->next)
			stk->top = stk->top->next;
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
	node_top(stk_b);
	pvot = pvot_init(stk_b);
	while (++i < size)
	{
		if (stk_b->top->data > pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RB);
			ps->rb++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PA);
			ps->pa++;
			stk_b->size--;
			stk_a->size++;
		}
		if (stk_b->top->next)
			stk_b->top = stk_b->top->next;
	}
	i = -1;
	while (++i < ps->rb)
		push_swap_init(stk_a, stk_b, ps, RRB);
	valid_init(stk_a, stk_b, ps);
	A_to_B(stk_a, stk_b, ps, ps->rb);
	B_to_A(stk_a, stk_b, ps, ps->pa);
}

void	A_to_B(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int i;
	int	pvot;

	if (size == 1)
		return ;
	ps->ra = 0;
	ps->pb = 0;
	node_top(stk_a);
	i = -1;
	while (++i < stk_a->size)
	{
		printf("%d ", stk_a->top->data);
		if (stk_a->top->next)
			stk_a->top = stk_a->top->next;
	}
	printf("\n");
	node_top(stk_a);
	pvot = pvot_init(stk_a);
	node_top(stk_a);
	i = -1;
	while (++i < stk_a->size)
	{
		printf("%d ", stk_a->top->data);
		if (stk_a->top->next)
			stk_a->top = stk_a->top->next;
	}
	printf("\n");
	node_top(stk_a);
	i = -1;
	while (++i < size)
	{
		printf("%d\n", stk_a->top->data);
		if (stk_a->top->data > pvot)
		{
			push_swap_init(stk_a, stk_b, ps, RA);
			ps->ra++;
		}
		else
		{
			push_swap_init(stk_a, stk_b, ps, PB);
			ps->pb++;
			stk_a->size--;
			stk_b->size++;
		}
		if (stk_a->top->next)
			stk_a->top = stk_a->top->next;
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
	print_finish(stk_a, stk_b, ps);
}
