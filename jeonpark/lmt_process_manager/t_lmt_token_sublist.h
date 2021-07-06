/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:03:05 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 19:21:28 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_TOKEN_SUBLIST_H
# define T_LMT_TOKEN_SUBLIST_H

# include "lmt_process_manager_typedef.h"

typedef struct s_lmt_token_sublist
{
	t_lmt_token	*first;
	t_lmt_token	*last;
}	t_lmt_token_sublist;

t_lmt_token_sublist	*lmt_token_sublist_new(t_lmt_token *first, t_lmt_token *last);
void	lmt_token_sublist_free(t_lmt_token_sublist *sublist);

#endif
