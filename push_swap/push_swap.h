/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:34 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 18:41:06 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct	s_stack_a
{
	s_stack_a	*pre;
	int			num;
	s_stack_a	*next;
}				t_stack_a;

typedef struce	s_stack_b
{
	s_stack_b	*pre;
	int			num;
	s_stack_b	*next;
}				t_stack_b;
