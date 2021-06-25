/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:47:39 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:56:14 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_reverse(t_stack *stk)
{
	t_stack *ptr;
	t_node	*n_ptr;
	int		tmp;

	ptr = stk;
	node_back(ptr);
	tmp = ptr->top->data;
	node_pop_back(ptr);
	node_front(ptr);
	ptr->top->pre = create_node(0);
	n_ptr = ptr->top->ptr;
	n_ptr->next = ptr->top;
	n_ptr->data = tmp;
}

void	ft_reverse(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == 9 || (sep == 11 && ps->size == 10))
		process_reverse(stk_a);
	else if (sep == 10 || (sep == 11 && ps->size == 9))
		process_reverse(stk_b);
}
