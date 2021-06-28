/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:03:09 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 16:56:10 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_rotate(t_stack *stk)
{
	t_node	*new_ptr;
	t_node	*bot_ptr;

	if (stk->size < 2)
		return ;
	stk->ptr = stk->top;
	bot_ptr = stk->bot;
	new_ptr = stk->top->next;
	bot_ptr->next = stk->ptr;
	stk->ptr->pre = bot_ptr;
	stk->bot = stk->ptr;
	stk->top = new_ptr;
	stk->ptr = stk->top;
	stk->bot->next = NULL;
	stk->top->pre = NULL;
}

void	ft_rotate(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep)
{
	if (sep == RA || (sep == RR && ps->cur == RB))
		process_rotate(stk_a);
	else if (sep == RB || (sep == RR && ps->cur == RA))
		process_rotate(stk_b);
}
