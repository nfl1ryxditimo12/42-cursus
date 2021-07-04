/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 17:23:21 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_list.h"
#include "t_lmt_process.h"
#include "lmt_util.h"

t_lmt_process	*lmt_process_list_new(void)
{
	return (lmt_process_new(NULL, NULL));
}

void	lmt_process_list_free(t_lmt_process *list)
{
	t_lmt_process	*element;
	t_lmt_process	*next_element;

	element = list;
	while (element != NULL)
	{
		next_element = element->next;
		lmt_process_free(element);
		element = next_element;
	}
	free(list);
}
