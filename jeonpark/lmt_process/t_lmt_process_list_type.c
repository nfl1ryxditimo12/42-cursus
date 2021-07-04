/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 18:56:09 by jeonpark         ###   ########.fr       */
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
	t_lmt_process	*iterator;
	t_lmt_process	*next;

	iterator = list;
	while (iterator != NULL)
	{
		next = iterator->next;
		lmt_process_free(iterator);
		iterator = next;
	}
	free(list);
}
