/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_sublist_method.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:12:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/25 13:26:46 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_token_sublist.h"
#include "lmt_extension_token.h"
#include "constant.h"

int	lmt_token_sublist_get_next_control_op(t_lmt_token_sublist *sublist)
{
	t_token	*next_control_op;

	if (sublist == NULL)
		return (TYPE_UNDEFINED);
	next_control_op = sublist->terminator;
	while (lmt_is_token_type_close_parenthesis(next_control_op))
		next_control_op = next_control_op->next;
	if (next_control_op == NULL)
		return (TYPE_TERMINATOR);
	return (next_control_op->type);
}
