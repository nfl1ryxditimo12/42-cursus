/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_sequence_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_sequence.h"
#include "t_lmt_sequence_element.h"
#include "lmt_alloc.h"

//	stdlib.h: free(), NULL

static t_lmt_sequence	*lmt_sequence_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_sequence)));
}

static void	lmt_sequence_init(t_lmt_sequence *sequence)
{
	t_lmt_sequence_element	*element;

	element = lmt_sequence_element_new(NULL);
	element->next = NULL;
	sequence->first = element;
	sequence->last = element;
}

t_lmt_sequence	*lmt_sequence_new(void)
{
	t_lmt_sequence	*sequence;

	sequence = lmt_sequence_alloc();
	lmt_sequence_init(sequence);
	return (sequence);
}

void	lmt_sequence_free(t_lmt_sequence *sequence, t_lmt_sequence_appliance content_free)
{
	t_lmt_sequence_element	*element_to_free;
	t_lmt_sequence_element	*element_next;

	element_to_free = sequence->first;
	element_next = element_to_free->next;
	while (element_to_free != sequence->last)
	{
		lmt_sequence_element_free(element_to_free, content_free);
		element_to_free = element_next;
		element_next = element_to_free->next;
	}
	lmt_sequence_element_free(element_to_free, content_free);
	free(sequence);
}
