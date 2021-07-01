/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:47:35 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:00:10 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_check2(t_stack *stk)
{
	t_node	*tmp;
	int		i;

	i = -1;
	if (stk->size != stk->arg)
		return (0);
	stk->ptr = stk->top;
	while (++i < stk->size)
	{
		if (stk->ptr->next)
			tmp = stk->ptr->next;
		else
			return (1);
		if (!(stk->ptr->data > tmp->data))
			return (0);
		if (stk->ptr->next)
			stk->ptr = stk->ptr->next;
	}
	return (1);
}

int		valid_check1(t_stack *stk)
{
	t_node	*tmp;
	int		i;

	i = -1;
	if (stk->size != stk->arg)
		return (0);
	stk->ptr = stk->top;
	while (++i < stk->size)
	{
		if (stk->ptr->next)
			tmp = stk->ptr->next;
		else
			return (1);
		if (!(stk->ptr->data < tmp->data))
			return (0);
		if (stk->ptr->next)
			stk->ptr = stk->ptr->next;
	}
	return (1);
}

int		stk_check(t_stack *stk)
{
	t_node	*tmp;
	int		i;

	i = -1;
	if (!stk->size)
		return (0);
	stk->ptr = stk->top;
	while (++i < stk->size)
	{
		if (stk->ptr->next)
			tmp = stk->ptr->next;
		else
			return (1);
		if (!(stk->ptr->data < tmp->data))
			return (0);
		if (stk->ptr->next)
			stk->ptr = stk->ptr->next;
	}
	return (0);
}

void	valid_process(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int proc)
{
	int i;
	int	size;

	i = -1;
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->top;
	size = stk_a->size ? stk_a->size : stk_b->size;
	if (proc == RRA || proc == PB)
	{
		if (proc == PB)
			while (++i < size)
				push_swap_init(stk_a, stk_b, ps, PB);
		i = -1;
		stk_a->ptr = stk_a->top;
		size = stk_b->size;
		while (++i < size * 2)
		{
			push_swap_init(stk_a, stk_b, ps, PA);
			push_swap_init(stk_a, stk_b, ps, RA);
		}
	}
	else if (proc == PA)
		while (++i < size)
			push_swap_init(stk_a, stk_b, ps, PA);
	print_finish(stk_a, stk_b, ps);
}

int		valid_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int	proc;

	proc = 0;
	if (stk_a->size == stk_a->arg)
	{
		proc = valid_check1(stk_a) ? 1 : 0;
		proc = valid_check2(stk_a) ? PB : proc;
	}
	if (stk_b->size == stk_b->arg)
	{
		proc = valid_check1(stk_b) ? RRA : 0;
		proc = valid_check2(stk_b) ? PA : proc;
	}
	if (proc)
		valid_process(stk_a, stk_b, ps, proc);
	else
		return (0);
	return (1);
}
