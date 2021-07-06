/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 20:23:50 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_lmt_process_manager.h"
#include "t_lmt_process_list.h"
#include "t_lmt_redirection_list.h"
#include "lmt_util.h"

//	stdlib.h: free()

static t_lmt_process_manager	*lmt_process_manager_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process_manager)));
}

static void	lmt_process_manager_init(t_lmt_process_manager *p_proman, t_lmt_token_list *token_list)
{
	p_proman->token_list = token_list;
	p_proman->token_sublist = lmt_token_sublist_new(token_list->p_dummy->next, token_list->last);
}

t_lmt_process_manager	*lmt_process_manager_new(void)
{
	t_lmt_process_manager	*p_proman;

	p_proman = lmt_process_manager_alloc();
	lmt_process_manager_init(p_proman);
	return (p_proman);
}

void	lmt_process_manager_free(t_lmt_process_manager *p_proman)
{
	lmt_token_list_free(p_proman->token_list);
	lmt_token_sublist_free(p_proman->token_sublist);
	free(p_proman);
}
