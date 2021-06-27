/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:07:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 03:23:07 by seonkim          ###   ########.fr       */
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
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->top;
	ps->ptr = ps->top;
	while (stk_a->size--)
		node_pop_top(stk_a);
	while (stk_b->size--)
		node_pop_top(stk_b);
	while (ps->size--)
		node_pop_top(ps);
}

void	print_finish(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int i = -1;

	ps->ptr = ps->top;
	stk_a->ptr = stk_a->top;
	stk_b->ptr = stk_b->top;
	while (++i < stk_a->size)
	{
		printf("%d ", stk_a->ptr->data);
		if (stk_a->ptr->next)
			stk_a->ptr = stk_a->ptr->next;
	}
	printf("\n");
	i = -1;
	while (++i < stk_b->size)
	{
		printf("%d ", stk_b->ptr->data);
		if (stk_b->ptr->next)
			stk_b->ptr = stk_b->ptr->next;
	}
	printf("\n");
	while (ps->ptr->next)
	{
		print_ps(ps->ptr->data);
		if (ps->ptr->next)
			ps->ptr = ps->ptr->next;
	}
	i = -1;
	stk_a->ptr = stk_a->top;
	printf("sorted : ");
	while (++i < 5)
	{
		printf("%d ", stk_a->ptr->data);
		if (stk_a->ptr->next)
			stk_a->ptr = stk_a->ptr->next;
	}
	printf("\n");
	//free_stack(stk_a, stk_b, ps);
	exit(0);
}
