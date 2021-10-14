/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/24 21:18:24 by jeonpark         ###   ########.fr       */
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

//	파싱이 끝난 handler 를 읽어 자식 프로세스 생성, 리다이렉션 적용,
//	'|', '&&', '||', '()' 에 따라 적절히 자식 프로세스를 생성하고
//	command 를 실행하는 함수를 호출한다
//
//	- 쓰임:
//	파싱이 끝난 후 이 함수를 호출하면 된다
//
//	- 반환값:
//	프로세스가 실행된 후 반환된 값
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
