/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_sequence.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:32:56 by jeonpark          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_SEQUENCE_H
# define T_LMT_SEQUENCE_H

# include "t_lmt_sequence_constant.h"
# include "t_lmt_sequence_element.h"

//	lmt_alloc(), free()

typedef struct s_lmt_sequence
{
	t_lmt_sequence_element	*first;
	t_lmt_sequence_element	*last;
}	t_lmt_sequence;

t_lmt_sequence	*lmt_sequence_new(void);
void			lmt_sequence_free(t_lmt_sequence *sequence, t_lmt_sequence_appliance content_free);

void			lmt_sequence_insert_first(t_lmt_sequence *sequence, void *content);
void			lmt_sequence_append(t_lmt_sequence *sequence, void *content);
void			*lmt_sequence_pop_first(t_lmt_sequence *sequence);
void			lmt_sequence_iterate(t_lmt_sequence *sequence, t_lmt_sequence_appliance appliance);

#endif
