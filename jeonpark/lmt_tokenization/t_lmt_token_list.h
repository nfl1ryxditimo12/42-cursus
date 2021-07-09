/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:23:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_LIST_H
# define T_LMT_TOKEN_LIST_H

# include "lmt_process_manager_typedef.h"

typedef struct s_lmt_token_list
{
	t_lmt_token	*p_dummy;
	t_lmt_token	*last;
}	t_lmt_token_list;

//	type function
t_lmt_token_list	*lmt_token_list_new();
t_lmt_token_list	*lmt_token_list_new_by_token(t_token *p_token);
void	lmt_token_list_free(t_lmt_token_list *list);

//	method function
void	lmt_token_list_append(t_lmt_token_list *list, t_lmt_token *p_element);
char	**lmt_token_get_argv(t_lmt_token_list *list);

#endif
