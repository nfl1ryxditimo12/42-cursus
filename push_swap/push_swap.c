/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:06:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/27 00:01:42 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		save_param(t_stack *ps, int sep)
{
	if ((ps->cur == SA && sep == SB) || (ps->cur == SB && sep == SA))
		sep = SS;
	else if ((ps->cur == RA && sep == RB) || (ps->cur == RB && sep == RA))
		sep = RR;
	else if ((ps->cur == RRA && sep == RRB) || (ps->cur == RRB && sep == RRA))
		sep = RRR;
	return (sep);
}

void	push_swap_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (!sep)
		return ;
	printf("before sep : %d", sep);
	sep = save_param(ps, sep);
	if (sep != SS || sep != RR || sep != RRR || !ps->top)
		node_push(ps, 0);
	ps->top->data = sep;
	printf(", after sep : %d\n\n", sep);
	if (SA <= sep && sep <= SS)
		ft_swap(stk_a, stk_b, ps, sep);
	else if (sep == PA || sep == PB)
		ft_push(stk_a, stk_b, sep);
	else if (RA <= sep && sep <= RR)
		ft_rotate(stk_a, stk_b, ps, sep);
	else if (RRA <= sep && sep <= RRR)
		ft_reverse(stk_a, stk_b, ps, sep);
	ps->cur = sep;
}
