/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:22 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:50:14 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stk_a;
	t_stack stk_b;
	t_stack	ps;

	if (ac <= 1)
		print_err(0, 0);
	stack_init(&stk_a, &stk_b, &ps, ac - 1);
	list_init(av, &stk_a);
	if (ac < 7)
		small_arg(&stk_a, &stk_b, &ps);
	sort_init(&stk_a, &stk_b, &ps);
	return (0);
}
