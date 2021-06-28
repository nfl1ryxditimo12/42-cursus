/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:27:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:58:48 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_swap(t_stack *stk)
{
	t_node	*ptr;
	int		tmp;

	stk->ptr = stk->top;
	ptr = stk->ptr;
	tmp = ptr->data;
	ptr->data = ptr->next->data;
	ptr->next->data = tmp;
}

void	ft_swap(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == SA || (sep == SS && ps->cur == SB))
		process_swap(stk_a);
	else if (sep == SB || (sep == SS && ps->cur == SA))
		process_swap(stk_b);
}
