/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 18:43:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"
#include "lmt_util.h"

static t_lmt_process_manager	*lmt_process_manager_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process_manager)));
}

static void	lmt_process_manager_init(t_lmt_process_manager *p_proman)
{
	p_proman->token_list = lmt_token_list_new();
	p_proman->process_list = lmt_process_list_new();
}

t_lmt_process_manager	*lmt_process_manager_new(void)
{
	t_lmt_process_manager	*p_proman;

	p_proman = lmt_process_manager_alloc();
	lmt_process_manager_init(p_proman);
	return (p_proman);
}

void	*lmt_process_manager_free(t_lmt_process_manager *p_proman)
{
	lmt_token_list_free(p_proman->token_list);
	lmt_process_list_free(p_proman->process_list);
	free(p_proman);
}
