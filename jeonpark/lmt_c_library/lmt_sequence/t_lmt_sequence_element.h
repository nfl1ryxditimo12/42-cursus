/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_sequence_element.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:52 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_SEQUENCE_ELEMENT_H
# define T_LMT_SEQUENCE_ELEMENT_H

# include "t_lmt_sequence_constant.h"

//	lmt_alloc(), free()

typedef struct s_lmt_sequence_element
{
	void							*content;
	struct s_lmt_sequence_element	*next;
}	t_lmt_sequence_element;

t_lmt_sequence_element	*lmt_sequence_element_new(void *content);
void					lmt_sequence_element_free(t_lmt_sequence_element *element, t_lmt_sequence_appliance content_free);

void					*lmt_sequence_element_pop(t_lmt_sequence_element *element);
void					lmt_sequence_element_apply(t_lmt_sequence_element *element, t_lmt_sequence_appliance appliance);

#endif
