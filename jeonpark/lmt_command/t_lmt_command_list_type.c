/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:48:01 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command_list.h"
#include "t_lmt_command.h"
#include "lmt_util.h"

t_lmt_command	*lmt_command_list_new(void)
{
	t_lmt_command	*list;

	list = lmt_command_new(NULL, NULL);
	return (list);
}

void	lmt_command_list_free(t_lmt_command *list)
{
	t_lmt_command	*element;
	t_lmt_command	*next_element;

	element = list;
	while (element != NULL)
	{
		next_element = element->next;
		lmt_command_free(element);
		element = next_element;
	}
	free(list);
}
