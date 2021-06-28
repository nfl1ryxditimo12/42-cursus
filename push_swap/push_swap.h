/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:34 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/28 17:28:40 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MEM_ERR "Memoey Error"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct	s_node
{
	int				data;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bot;
	t_node	*ptr;
	int		size;
	int		cur;
	int		arg;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}				t_stack;

t_node			*create_node(char *str);

int				str_to_nbr(char *str, int sep);

int				valid_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps);
int				valid_check1(t_stack *stk);
int				valid_check2(t_stack *stk);
void			small_arg(t_stack *stk_a, t_stack *stk_b, t_stack *ps);

void			check_arg(char **arr, int len);

void			list_init(char **av, t_stack *stk_a);
void			stack_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int ac);

void			print_err(char *err, char *arr);
void			print_finish(t_stack *stk_a, t_stack *stk_b, t_stack *ps);

t_node			*node_top(t_stack *stk);
t_node			*node_bottom(t_stack *stk);
void			node_push(t_stack *stk, char *str);
void			node_pop_top(t_stack *stk);
void			node_pop_bottom(t_stack *stk);
t_node			*node_init(char *str);

void			sort_init(t_stack *stk_a, t_stack *stk_b, t_stack *ps);
void			a_to_b(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size);
void			b_to_a(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int size);
int				pvot_init(t_stack *stk, int size);

void			ft_swap(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep);
void			ft_push(t_stack *stk_a, t_stack *stk_b, int sep);
void			ft_rotate(t_stack *stk_a, t_stack *stk_b, t_stack *ps, int sep);
void			ft_reverse(t_stack *stk_a, t_stack *stk_b,
		t_stack *ps, int sep);

void			push_swap_init(t_stack *stk_a, t_stack *stk_b,
		t_stack *ps, int sep);

#endif
