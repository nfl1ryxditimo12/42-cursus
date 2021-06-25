/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:27:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:36:56 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_swap(t_stack *stk)
{
	t_stack *ptr;
	int tmp;

	ptr = stk->top;
	node_front(ptr);
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
}

void	ft_swap(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == 1 || (sep == 3 && ps->size == 2))
		process_swap(stk_a);
	else if (sep == 2 || (sep == 3 && ps->size == 1))
		process_swap(stk_b);
}
