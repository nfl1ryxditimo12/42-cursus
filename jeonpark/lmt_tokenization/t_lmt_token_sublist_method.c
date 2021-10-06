/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist_method.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:46:33 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 06:02:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_token_sublist.h"
#include "minishell.h"

const char	*lmt_token_sublist_get_current_word(t_lmt_token_sublist *sublist)
{
	return (sublist->word_current);
}

void	*lmt_token_sublist_move_next_word(t_lmt_token_sublist *sublist)
{
	sublist->word_current++;
	if (lmt_is_token_word_out_of_range(sublist->word_current))
	{
		++sublist->token_current;
	}
}
