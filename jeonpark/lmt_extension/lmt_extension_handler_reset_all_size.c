/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_extension_handler_reset_all_size.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:26:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:27:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_extension_token.h"

void	lmt_reset_handler_all_size(t_handler *handler)
{
	int		count;
	t_token	*element;

	count = 0;
	element = handler->top;
	while (element != NULL)
	{
		element->size
			= lmt_count_of_null_terminated_array((void **)element->token);
		++count;
		element = element->next;
	}
	handler->token_size = count;
}
