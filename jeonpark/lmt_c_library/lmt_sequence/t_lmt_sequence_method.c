/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_sequence_method.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:50 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_lmt_sequence.h"
#include "t_lmt_sequence_element.h"

void	lmt_sequence_insert_first(t_lmt_sequence *sequence, void *content)
{
	t_lmt_sequence_element	*element;

	element = lmt_sequence_element_new(content);
	element->next = sequence->first->next;
	sequence->first->next = element;
	if (sequence->last == sequence->first)
		sequence->last = element;
}

void	lmt_sequence_append(t_lmt_sequence *sequence, void *content)
{
	t_lmt_sequence_element	*element;

	element = lmt_sequence_element_new(content);
	element->next = NULL;
	sequence->last->next = element;
	sequence->last = element;
}

void	*lmt_sequence_pop_first(t_lmt_sequence *sequence)
{
	t_lmt_sequence_element	*element;

	element = sequence->first->next;
	if (element == NULL)
		return (NULL);
	sequence->first->next = element->next;
	if (sequence->last == element)
		sequence->last = sequence->first;
	return (lmt_sequence_element_pop(element));
}

void	lmt_sequence_iterate(t_lmt_sequence *sequence, t_lmt_sequence_appliance appliance)
{
	t_lmt_sequence_element	*element;

	element = sequence->first->next;
	while (element != NULL)
	{
		lmt_sequence_element_apply(element, appliance);
		element = element->next;
	}
}
