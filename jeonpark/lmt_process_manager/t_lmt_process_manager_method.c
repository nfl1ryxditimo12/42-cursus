/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 22:33:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"
#include "t_lmt_process_list.h"
#include "t_lmt_redirection_list.h"
#include "t_lmt_process.h"
#include "minishell.h"
#include "lmt_util.h"

int	lmt_process_manager_execute(t_lmt_token_sublist *token_sublist)
{
	t_lmt_process_list	*process_list;
	int	exit_code;

	lmt_process_list_set_by_lmt_token_sublist(process_list, token_sublist);
	exit_code = lmt_process_list_execute(p_proman->process_list, env);
	lmt_process_list_free(process_list);
	return (exit_code);
}

int	lmt_process_manager_execute_by_handler(t_handler *hand)
{
	t_lmt_process_manager *p_proman;
	int	ret;

	p_proman = lmt_program_manager_new(lmt_token_list_new_by_token(hand->top));
	ret = lmt_process_manager_execute(token_sublist);
	lmt_process_manageer_free(p_proman);
	return (ret);
}
