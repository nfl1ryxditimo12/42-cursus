/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:03:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:47:25 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_rotate(t_stack *stk, t_stack *ps)
{
	t_stack	*ptr;
	t_node	*n_ptr;
	int		tmp;

	ptr = stk;
	node_front(ptr->top);
	tmp = ptr->top->data;
	node_pop(ptr);
	node_back(ptr->top);
	ptr->top->next = create_node(0);
	n_ptr = ptr->top->next;
	n_ptr->ptr = ptr->top;
	n_ptr->data = tmp;
}

void	ft_rotate(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == 6 || (sep == 8 && ps->size == 7))
		process_rotate(stk_a, ps);
	else if (sep == 7 || (sep == 8 && ps->size == 6))
		process_rotate(stk_b, ps);
}
