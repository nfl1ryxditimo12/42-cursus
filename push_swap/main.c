/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:22 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 18:37:49 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_a stk_a;
	t_stack_b stk_b;

	if (ac > 1)
	{
		(*av++);
		stack_init(av, ac - 1, stk_a, stk_b);
		check_arg(av, ac - 1, stk_a);
	}
	else
		print_err("Argument not enough");
	return (0);
}
