/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 14:05:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_SUBLIST_H
# define T_LMT_TOKEN_SUBLIST_H

# include "minishell.h"

typedef struct s_lmt_token_sublist
{
	t_token	*first;
	t_token	*last;
}	t_lmt_token_sublist;

//	타입 함수
t_lmt_token_sublist	*lmt_token_sublist_new(t_token *first, t_token *last);
void	lmt_token_sublist_free(t_lmt_token_sublist *sublist);

#endif
