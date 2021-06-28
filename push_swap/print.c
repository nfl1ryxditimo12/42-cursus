/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:07:12 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 19:12:04 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(char *err, char *arr)
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
	int i;
	int	size;

	i = -1;
	stk_a->ptr = stk_a->top;
	ps->ptr = ps->top;
	size = stk_a->size;
	while (++i < size)
		node_pop_top(stk_a);
	i = -1;
	size = ps->size;
	while (++i < size)
		node_pop_top(ps);
	stk_a->top = NULL;
	stk_a->ptr = NULL;
	stk_a->bot = NULL;
	stk_b->top = NULL;
	stk_b->ptr = NULL;
	stk_b->bot = NULL;
	ps->top = NULL;
	ps->ptr = NULL;
	ps->bot = NULL;
}

void	print_finish(t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int i;

	ps->ptr = ps->top;
	stk_a->ptr = stk_a->top;
	i = -1;
	while (++i < ps->size)
	{
		print_ps(ps->ptr->data);
		if (ps->ptr->next)
			ps->ptr = ps->ptr->next;
	}
	stk_a->ptr = stk_a->top;
	/*for (int i = 0; i < stk_a->size; i++)
	{
		printf("%d ", stk_a->ptr->data);
		if (stk_a->ptr->next)
			stk_a->ptr = stk_a->ptr->next;
	}
	printf ("\n");*/
	stk_a->ptr = stk_a->top;
	free_stack(stk_a, stk_b, ps);
	exit(0);
}
