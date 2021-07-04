/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 19:06:53 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"
#include "lmt_util.h"

void	lmt_process_manager_read_token(t_lmt_process_manager *p_proman, t_token *p_token)
{
	t_token	*iterator;
	char	*iterator_string;

	iterator = p_token;
	while (iterator != NULL)
	{
		iterator_string = iterator->token;
		while (iterator_string != NULL)
		{
			
			++iterator_string;
		}
		iterator = iterator->next;
	}
}

void	lmt_process_manager(t_lmt_token *p_list)
{
}
