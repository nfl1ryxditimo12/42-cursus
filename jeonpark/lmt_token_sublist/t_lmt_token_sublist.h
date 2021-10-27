/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 16:14:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_SUBLIST_H
# define T_LMT_TOKEN_SUBLIST_H

# include "minishell.h"

typedef struct s_lmt_token_sublist
{
	t_token	*first;
	t_token	*terminator;
}	t_lmt_token_sublist;

//	type function
t_lmt_token_sublist	*lmt_token_sublist_new(t_token *first, t_token *terminator);
void				lmt_token_sublist_free(t_lmt_token_sublist *sublist);

//	method function
int					lmt_token_sublist_get_next_control_op(
						t_lmt_token_sublist *sublist);

#endif
