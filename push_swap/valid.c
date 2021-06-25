/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:47:35 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 16:57:02 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_check(t_stack *stk)
{
	t_stack *tmp;

	if (stk->size != stk->c_size)
		return (0);
	node_front(stk);
	while (stk->top->next)
	{
		tmp = stk->top->next;
		while (tmp->top->next)
		{
			if (!(stk->top->data < tmp->top->data))
				return (0);
			tmp->top = tmp->top->next;
		}
		stk->top = stk->top->next;
		i++;
	}
	return (1);
}
