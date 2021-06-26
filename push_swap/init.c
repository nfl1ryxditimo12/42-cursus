/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:36:42 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/26 22:49:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(char *str)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
			print_err(MEM_ERR, 0);
	node->data =  str_to_nbr(str, 0);
	node->pre = NULL;
	node->next = NULL;
	return (node);
}

void	stack_process(t_stack *stk, int ac)
{
	stk->top = NULL;
	stk->cur = 0;
	stk->size = 0;
	stk->arg = ac;
	stk->ra = 0;
	stk->rb = 0;
	stk->pa = 0;
	stk->pb = 0;
}

void	stack_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int ac)
{
	stack_process(stk_a, ac);
	stack_process(stk_b, ac);
	stack_process(ps, ac);
}

void	list_init(char **av, t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int i;

	av++;
	i = -1;
	check_arg(av, stk_a->arg);
	while (++i < stk_a->arg)
	{
		node_push(stk_a, *av);
		av++;
	}
	node_top(stk_a);
}
