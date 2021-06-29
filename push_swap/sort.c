/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:02:48 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/29 12:54:08 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pvot_init(t_stack *stk, int size)
{
	int		*arr;
	int		i;
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
	tmp = pvot_util(arr, size);
	free(arr);
	return (tmp);
}

void	b_to_a(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int	rb;
	int pa;

	if (size == 1)
	{
		push_swap_init(stk_a, stk_b, ps, PA);
		return ;
	}
	ps->flag = 1;
	stk_b->ptr = stk_b->top;
	stk_a->ptr = stk_a->size ? stk_a->top : NULL;
	sort_util_b(stk_a, stk_b, ps, size);
	rb = ps->rb;
	pa = ps->pa;
	ps->rb = 0;
	ps->pa = 0;
	a_to_b(stk_a, stk_b, ps, pa);
	b_to_a(stk_a, stk_b, ps, rb);
}

void	a_to_b(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size)
{
	int	ra;
	int	pb;

	if (size == 1)
		return ;
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->size ? stk_b->top : NULL;
	sort_util_a(stk_a, stk_b, ps, size);
	ra = ps->ra;
	pb = ps->pb;
	ps->ra = 0;
	ps->pb = 0;
	a_to_b(stk_a, stk_b, ps, ra);
	b_to_a(stk_a, stk_b, ps, pb);
}

void	sort_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	if (!valid_init(stk_a, stk_b, ps))
		a_to_b(stk_a, stk_b, ps, stk_a->size);
	print_finish(stk_a, stk_b, ps);
}
