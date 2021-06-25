/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:36:42 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:53:52 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(char *str)
{
	t_node	*stk;

	if (!(stk = malloc(sizeof(t_node))))
			print_err(MEM_ERR);
	if (!str)
		stk->data = 0;
	else
		stk->data =  str_to_nbr(str);
	stk->pre = NULL;
	stk->next = NULL;
	return (stk);
}

t_stack	*stack_init(void)
{
	t_stack	*stk;

	if (!(stk = malloc(sizeof(t_stack))))
		print_err(MEM_ERR);
	stk->top = NULL;
	stk->c_size = 0;
	stk->size = 0;
	return (stk);
}

void	list_init(char **av, t_stack *stk_a, t_stack *stk_b, t_stack *ps)
{
	int i;

	i = -1;
	av++;
	stk_a = stack_init();
	stk_b = stack_init();
	ps = stack_init();
	ps->top = create_node(0);
	check_arg(av, stk_a->size);
	while (++i < stk_a->size)
	{
		node_push(stk_a, *av);
		node_push(stk_b, 0);
		av++;
	}
	node_front(stk_a->top);
	node_front(stk_b->top);
}
