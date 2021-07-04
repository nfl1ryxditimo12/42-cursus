/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 12:14:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command_list.h"
#include "lmt_util.h"

void	lmt_command_list_push(t_lmt_command *p_list, t_token *p_token)
{
	t_lmt_command *p_element;

	p_element = lmt_command_new(p_token);
	p_element->next = p_list->next;
	p_list->next = p_element;
}
