/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_token_list_method.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:18:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 12:05:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_lmt_token_list.h"
#include "t_lmt_token.h"
#include "lmt_util.h"

void	lmt_token_list_append(t_lmt_token_list *list, int type, char *string)
{
	t_lmt_token	*p_element;

	p_element = lmt_token_new(type, string);
	list->p_bottom->next = p_element;
	p_element->next = NULL;
	list->p_bottom = p_element;
}
