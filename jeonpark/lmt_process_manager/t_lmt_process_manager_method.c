/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 10:54:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "t_lmt_process_manager.h"

//	token_sublist 의 범위 안에 있는 token 들로
//	process 를 구성하고 실행한다
//
//	- 쓰임:
//	lmt_process_manager_execute() 안에서,
//	또는 type 이 parenthesis 인 lmt_process 를 execute 할 때 호출한다
//
//	- 반환값:
//	프로세스가 실행된 후 반환된 값
int	lmt_process_manager_execute_token_sublist(t_handler *handler, t_lmt_token_sublist *token_sublist)
{
	t_lmt_process_list	*process_list;
	int					exit_code;

	process_list = lmt_process_list_new();
	lmt_process_list_set_by_token_sublist(process_list, token_sublist);
	exit_code = lmt_process_list_execute(process_list, handler);
	lmt_process_list_free(process_list);
	return (exit_code);
}

static int	refine_token(t_handler *handler)
{
	int	return_value;

	lmt_set_token_type(handler->top);
	return_value = lmt_check_syntax_error(handler->top);
	if (return_value == PARSE_FAILURE)
	{
		printf("parse error. \n");
		return (PARSE_FAILURE);
	}
	lmt_arrange_token(handler);
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
int	lmt_process_manager_execute(t_handler *handler)
{
	t_lmt_token_sublist	*token_sublist;
	int					return_value;
	int					exit_code;

	return_value = refine_token(handler);
	if (return_value == PARSE_FAILURE)
		return (PARSE_FAILURE);	// 이것때문에 refine_token() 을 밖에서 호출하거나, exit_code 를 다른 방식으로 callee 에게 전달해야 할 것 같다
	token_sublist = lmt_token_sublist_new(handler->top, NULL);
	exit_code = lmt_process_manager_execute_token_sublist(handler, token_sublist);
	lmt_token_sublist_free(token_sublist);
	return (exit_code);
}
