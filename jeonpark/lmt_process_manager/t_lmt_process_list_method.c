/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/09 20:00:11 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/wait.h>
#include "t_lmt_process_manager.h"

//	stddef.h: NULL
//	sys/wait.h: waitpid()

//	push 가 top 에 새로운 node 를 추가한다면, append 는 bottom 에 새로운 노드를 추가한다
void	lmt_process_list_append(t_lmt_process_list *list, t_lmt_process *element)
{
	element->prev = list->last;
	element->next = NULL;
	list->last->next = element;
	list->last = element;
}

//	정상적으로 fork 된 자식 프로세스를 기다리는 함수
static int	lmt_process_list_wait(t_lmt_process_list *list)
{
	t_lmt_process	*element;
	int	stat_loc;

	element = list->p_dummy->next;
	while (element != NULL)
	{
		if (element->next_operator == TYPE_CONTROL_OPERATOR_PIPE || element->next_operator == TYPE_TERMINATOR)
			if (element->pid != 0)
				waitpid(element->pid, &stat_loc, 0);
		element = element->next;
	}
	return (lmt_get_exit_code_from_stat_loc(stat_loc));
}

//	두 번째 인자로 받은 token_sublist 를 읽어
//	lmt_process 를 생성해 lmt_process_list 에 list 형식으로 저장해둔다
//
//	- 쓰임:
//	lmt_process_manager_execute_token_sublist() 안에서
//	lmt_process_list_new() 로 process_list 를 생성한 후,
//	lmt_process_list_execute() 를 호출하기 전에
//	이 함수를 호출한다
void	lmt_process_list_set_by_token_sublist(t_lmt_process_list *list, t_lmt_token_sublist *token_sublist)
{
	t_token				*element;
	t_lmt_process		*p_process_new;
	int					parenthesis_count;
	t_token				*p_process_first_token;
	t_lmt_token_sublist	*token_sublist_new;

	element = token_sublist->first;
	while (element != token_sublist->terminator)
	{
		if (element->type == TYPE_OPEN_PARENTHESIS)
		{
			parenthesis_count = 1;
			p_process_first_token = element->next;
			while (parenthesis_count > 0)
			{
				element = element->next;
				if (element->type == TYPE_OPEN_PARENTHESIS)
					++parenthesis_count;
				else if (element->type == TYPE_CLOSE_PARENTHESIS)
					--parenthesis_count;
			}
			token_sublist_new = lmt_token_sublist_new(p_process_first_token, element);
			p_process_new = lmt_process_new(TYPE_PROCESS_SUBSHELL, token_sublist_new);
			lmt_process_list_append(list, p_process_new);
			element = element->next;
		}
		else
		{
			p_process_first_token = element;
			while (!lmt_is_token_type_control_operator(element) || element != NULL)
				element = element->next;
			token_sublist_new = lmt_token_sublist_new(p_process_first_token, element);
			p_process_new = lmt_process_new(TYPE_PROCESS_NORMAL, token_sublist_new);
			lmt_process_list_append(list, p_process_new);
		}
		if (lmt_is_token_type_control_operator(element))
			element = element->next;
	}
}

//	list 안에 만들어 놓은 lmt_process 들을 순차적으로 돌면서
//	lmt_process 의 op 에 따라 필요한 처리를 하고
//	lmt_process_execute() 를 호출한다
//
//	- 쓰임:
//	lmt_process_manager_execute_token_sublist() 안에서
//	lmt_process_list 의 생성 및 값 설정을 마친 후
//	이 함수를 호출한다
//
//	- 반환값:
//	프로세스가 실행되고 난 후 반환된 값
int	lmt_process_list_execute(t_lmt_process_list *list, t_handler *p_handler)
{
	t_lmt_process		*element;
	int					stat_loc;
	int					exit_code;

	element = list->p_dummy->next;
	while (element != NULL)
	{
		if (element->next_operator == TYPE_CONTROL_OPERATOR_PIPE)
		{
			lmt_process_append_pipe_redirection(element);
			lmt_process_execute_child(element, p_handler);
		}
		else if (element->prev->next_operator == TYPE_CONTROL_OPERATOR_PIPE)
			lmt_process_execute_child(element, p_handler);
		else
		{
			if (builtin_cmd(p_handler))
				exit_code = lmt_process_execute_parent(element, p_handler);
			else
			{
				lmt_process_execute_child(element, p_handler);
				waitpid(element->pid, &stat_loc, 0);
				exit_code = lmt_get_exit_code_from_stat_loc(stat_loc);
			}
			if ((element->next_operator == TYPE_CONTROL_OPERATOR_AND && exit_code == 0)
					|| (element->next_operator == TYPE_CONTROL_OPERATOR_OR && exit_code != 0))
			{
				lmt_process_list_wait(list);
				return (exit_code);
			}
		}
		element = element->next;
	}
	exit_code = lmt_process_list_wait(list);
	return (exit_code);
}
