/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 16:13:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "t_lmt_process_manager.h"

static int	refine_token(t_handler *handler)
{
	int	return_value;

	lmt_set_token_type(handler->top);
	return_value = lmt_check_syntax_error(handler->top);
	if (return_value == PARSE_FAILURE)
		return (return_value);
	lmt_convert_list(handler);
	lmt_arrange_token(handler);
	lmt_reset_handler_all_size(handler);
	printf("\n\x1b[34m=======\x1b[0m Convert \x1b[34m===================================\x1b[0m\n\n");
	print_parse(handler);
	printf("\n\x1b[34m===================================================\x1b[0m\n\n");
	printf("\n\x1b[31m=======\x1b[0m Process \x1b[31m===================================\x1b[0m\n\n");
	return (PARSE_SUCCESS);
}

void	lmt_process_manager_execute(t_handler *handler)
{
	t_lmt_token_sublist		*token_sublist;
	t_lmt_process_manager	*manager;
	int						return_value;

	return_value = refine_token(handler);
	if (return_value == PARSE_FAILURE)
	{
		printf("parse error. \n");
		return ;
	}
	token_sublist = lmt_token_sublist_new(handler->top, NULL);
	manager = lmt_process_manager_new(handler, token_sublist);
	lmt_process_list_execute(manager->process_list, manager);
	lmt_token_sublist_free(token_sublist);
	lmt_process_manager_free(manager);
}
