/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:07:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 22:10:52 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(char *err, void *arr)
{
	while (*err)
		write(1, err++, 1);
	write(1, "\n", 1);
	if (arr)
		free(arr);
	exit(-1);
}

void	print_ps(int data)
{
	if (data == SA)
		write(1, "sa", 2);
	else if (data == SB)
		write(1, "sb", 2);
	else if (data == SS)
		write(1, "ss", 2);
	else if (data == PA)
		write(1, "pa", 2);
	else if (data == PB)
		write(1, "pb", 2);
	else if (data == RA)
		write(1, "ra", 2);
	else if (data == RB)
		write(1, "rb", 2);
	else if (data == RR)
		write(1, "rr", 2);
	else if (data == RRA)
		write(1, "rra", 3);
	else if (data == RRB)
		write(1, "rrb", 3);
	else if (data == RRR)
		write(1, "rrr", 3);
	write(1, "\n", 1);
}

void	free_stack(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	node_top(stk_a);
	node_top(stk_b);
	node_top(ps);
	while (stk_a->top)
		node_pop_top(stk_a);
	while (stk_b->top)
		node_pop_top(stk_b);
	while (ps->top)
		node_pop_top(ps);
	free(stk_a);
	free(stk_b);
	free(ps);
}

void	print_finish(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	node_top(ps);
	int i = -1;
	node_top(stk_a);
	node_top(stk_b);
	while (++i < stk_a->cur)
	{
		printf("a num : %d\n", stk_a->top->data);
		if (stk_a->top->next)
			stk_a->top = stk_a->top->next;
	}
	i = -1;
	while (++i < stk_b->cur)
	{
		printf("a num : %d\n", stk_b->top->data);
		if (stk_b->top->next)
			stk_b->top = stk_b->top->next;
	}
	while (ps->top->next)
	{
		print_ps(ps->top->data);
		if (ps->top->next)
			ps->top = ps->top->next;
	}
	free_stack(stk_a, stk_b, ps);
	exit(0);
}
