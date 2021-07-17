/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/17 13:32:40 by jeonpark         ###   ########.fr       */
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
	t_lmt_process	*iterator;
	int	stat_loc;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == TYPE_OPERATOR_PIPE || iterator->op == TYPE_NONE)
			if (iterator->pid != 0)
				waitpid(iterator->pid, &stat_loc, 0);
		iterator = iterator->next;
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
void	lmt_process_list_set_by_token_sublist(t_lmt_process_list *list, t_lmt_token_sublist *sublist)
{
	t_token				*iterator;
	t_lmt_process		*p_element;
	int					parenthesis_count;
	t_token				*p_process_first_token;
	t_lmt_token_sublist	*sublist_new;
	int					process_type;

	iterator = sublist->first;
	while (iterator != sublist->terminator)
	{
		if (iterator->type == TYPE_PARENTHESIS_OPEN)
		{
			parenthesis_count = 1;
			p_process_first_token = iterator->next;
			while (parenthesis_count > 0)
			{
				iterator = iterator->next;
				if (iterator->type == TYPE_PARENTHESIS_OPEN)
					++parenthesis_count;
				else if (iterator->type == TYPE_PARENTHESIS_CLOSE)
					--parenthesis_count;
			}
			sublist_new = lmt_token_sublist_new(p_process_first_token, iterator);
			if (iterator->next == NULL)
				process_type = TYPE_NONE;
			else
				process_type = iterator->next->type;
			p_element = lmt_process_new(TYPE_PROCESS_SUBSHELL, sublist_new, process_type);
			lmt_process_list_append(list, p_element);
			iterator = iterator->next;
		}
		else
		{
			p_process_first_token = iterator;
			while (!lmt_is_token_type_operator(iterator))
				iterator = iterator->next;
			sublist_new = lmt_token_sublist_new(p_process_first_token, iterator);
			if (iterator->next == NULL)
				process_type = TYPE_NONE;
			else
				process_type = iterator->next->type;
			p_element = lmt_process_new(TYPE_PROCESS_NORMAL, sublist_new, process_type);
			lmt_process_list_append(list, p_element);
		}
		if (lmt_is_token_type_operator(iterator))
			iterator = iterator->next;
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
	t_lmt_process		*iterator;
	int					fd_pipe[2];
	t_lmt_redirection	*p_redirection;
	int					stat_loc;
	int					exit_code;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->op == TYPE_OPERATOR_PIPE)
		{
			if (pipe(fd_pipe) == -1)
				lmt_exit(0, "Pipe error has occured \n");
			p_redirection = lmt_redirection_new(FD_OUT, -1, fd_pipe[PIPE_WRITE], NULL);
			lmt_process_append_redirection(iterator, p_redirection);
			p_redirection = lmt_redirection_new(FD_IN, -1, fd_pipe[PIPE_READ], NULL);
			lmt_process_append_redirection(iterator->next, p_redirection);
			lmt_process_execute_child(iterator, p_handler);
			close(fd_pipe[PIPE_WRITE]);
			p_redirection = lmt_redirection_new(-1, -1, fd_pipe[PIPE_READ], NULL);
			lmt_redirection_list_append(list->redirection_to_close_list, p_redirection);
		}
//	pipe 를 제외한 모든 op 에 대해 builtin command 가 parent 에서 실행되는 것이 아니다
//	이전 process 의 op 가 pipe 인지 확인하도록 수정하자
		else if (iterator->op != TYPE_NONE)
		{
			lmt_process_set(iterator);
			if (0 /* is_builtin(lmt_process_argv(iterator)[0]) */)
				exit_code = lmt_process_execute_parent(iterator, p_handler);
			else
			{
				lmt_process_execute_child(iterator, p_handler);
				waitpid(iterator->pid, &stat_loc, 0);
				exit_code = lmt_get_exit_code_from_stat_loc(stat_loc);
			}
			if ((iterator->op == TYPE_OPERATOR_AND && exit_code == 0)
					|| (iterator->op == TYPE_OPERATOR_OR && exit_code != 0))
			{
				lmt_process_list_wait(list);
				return (exit_code);
			}
		}
		else
			lmt_process_execute_child(iterator, p_handler);
		iterator = iterator->next;
	}
	exit_code = lmt_process_list_wait(list);
	return (exit_code);
}
