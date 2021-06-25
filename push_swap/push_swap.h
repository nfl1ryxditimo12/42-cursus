/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:34 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/25 19:05:26 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <stdio.h>


# define MEM_ERR "Memoey Error"

typedef struct	s_node
{
	int		data;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*top_a;
	t_node	*top_b;
	int		size;
	int		c_size;
}				t_stack;

t_stack	*stack_init(void);

t_node	*create_node(char *str);

int		str_to_nbr(char *str);

int		valid_check(t_stack *stk);

void	check_arg(char **arr, int len);

void	list_init(char **av, int size, t_stack *stk_a, t_stack *stk_b);

void	print_err(char *err);
void	print_nbr_err(char *err, void *str);

void	node_front(t_stack *stk);
void	node_back(t_stack *stk);
void	node_push(t_stack *stk, char *str);

#endif
