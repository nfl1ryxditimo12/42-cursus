/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:06:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 20:32:41 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		save_param(t_stack *ps, int sep, int tmp)
{
	int tmp_data;

	tmp_data = ps->top->data;
	if ((ps->size == 1 && sep == 2) || (ps->size == 2 && sep == 1))
		ps->top->data = 3;
	else if ((ps->size == 6 && sep == 7) || (ps->size == 7 && sep == 6))
		ps->top->data = 8;
	else if ((ps->size == 9 && sep == 10) || (ps->size == 10 && sep == 9))
		ps->top->data = 11;
	if (tmp_data != ps->top->data)
		return (ps->top->data);
	return (sep);
}

void	push_swap_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	sep = save_param(ps, sep);
	if (sep != 3 || sep != 8 || sep != 11)
		node_push(ps, 0);
	ps->top->data = sep;
	if (1 <= sep && sep <= 3)
		ft_swap(stk_a, stk_b, ps, sep);
	else if (sep == 4 || sep == 5)
		ft_push(stk_a, stk_b, ps, sep);
	else if (6 <= sep && sep <= 8)
		ft_rotate(stk_a, stk_b, ps, sep);
	else
		ft_reverse(stk_a, stk_b, ps, sep);
	ps->size = sep;
}
