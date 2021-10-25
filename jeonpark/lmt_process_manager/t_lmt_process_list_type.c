/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 21:20:18 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// free(), NULL
#include "t_lmt_process_manager.h"

static void	lmt_process_list_init(t_lmt_process *dummy)
{
	dummy->prev = dummy;
	dummy->next = dummy;
}

t_lmt_process	*lmt_process_list_new(void)
{
	t_lmt_process	*dummy;

	dummy = lmt_process_new(TYPE_PROCESS_DUMMY, NULL);
	lmt_process_list_init(dummy);
	return (dummy);
}

void	lmt_process_list_free(t_lmt_process *dummy)
{
	t_lmt_process	*element;
	t_lmt_process	*next;

	element = dummy->next;
	next = element->next;
	while (element != dummy)
	{
		if (element->list != NULL)
			lmt_process_list_free(element->list);
		lmt_process_free(element);
		element = next;
		next = element->next;
	}
	free(dummy);
}
