/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 21:47:05 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_LIST_H
# define T_LMT_TOKEN_LIST_H

typedef struct s_lmt_token_list
{
	t_lmt_token	*p_dummy;
	t_lmt_token	*p_bottom;
}	t_lmt_token_list;

//	type function
t_lmt_token_list	*lmt_token_list_new();
void	lmt_token_list_free(t_lmt_token *list);

//	method function
void	lmt_token_list_append(t_lmt_token_list *list, int type, char *string);

#endif
