/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 21:15:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_SUBLIST_H
# define T_LMT_TOKEN_SUBLIST_H

# include "minishell.h"

//	시작 t_token 과 끝 t_token 을 담아두는 구조체
//	실제 t_token 은 건들이지 않으면서
//	시작과 끝 token 의 주소를 기억하는 용도로 사용한다
typedef struct s_lmt_token_sublist
{
	t_token	*first;
	t_token	*terminator;
}	t_lmt_token_sublist;

//	type function
t_lmt_token_sublist	*lmt_token_sublist_new(t_token *first, t_token *terminator);
void	lmt_token_sublist_free(t_lmt_token_sublist *sublist);

//	method function
int	lmt_token_sublist_get_next_control_op(t_lmt_token_sublist *sublist);

#endif
