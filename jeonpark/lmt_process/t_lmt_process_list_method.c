/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 22:23:30 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_list.h"
#include "lmt_util.h"

void	lmt_process_list_append(t_lmt_process_list *list, char **argv, t_lmt_redirection **redirection_array)
{
	t_lmt_process *p_element;

	p_element = lmt_process_new(argv, redirection_array);
	list->bottom->next = p_element;
	p_element->next = NULL;
	list->bottom = p_element;
}

void	lmt_process_list_execute(t_lmt_process_list *list, char **env)
{
	t_lmt_process	*iterator;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		lmt_process_execute_process(iterator, env);
		iterator = iterator->next;
	}
}
