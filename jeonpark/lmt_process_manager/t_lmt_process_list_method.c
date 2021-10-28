/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/25 12:47:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

//	push 가 top 에 새로운 node 를 추가한다면, append 는 bottom 에 새로운 노드를 추가한다
void	lmt_process_list_append(t_lmt_process *dummy, t_lmt_process *element)
{
	element->prev = dummy->prev;
	element->next = dummy;
	element->prev->next = element;
	element->next->prev = element;
}

t_lmt_process	*lmt_process_dummy(t_lmt_process *process)
{
	t_lmt_process	*element;

	element = process;
	while (element->type != TYPE_PROCESS_DUMMY)
		element = element->next;
	return (element);
}

t_lmt_process	*lmt_process_prev(t_lmt_process *process)
{
	t_lmt_process	*prev_process;

	prev_process = process->prev;
	if (prev_process->type == TYPE_PROCESS_DUMMY)
	{
		if (prev_process->list != NULL)
			return (lmt_process_prev(prev_process->list));
		else
			return (NULL);
	}
	else if (prev_process->type == TYPE_PROCESS_NORMAL)
		return (prev_process);
	else if (prev_process->type == TYPE_PROCESS_PARENTHESIS)
		return (lmt_process_prev(prev_process->list));
	else
		return (NULL);
}

t_lmt_process	*lmt_process_next(t_lmt_process *process)
{
	t_lmt_process	*next_process;

	next_process = process->next;
	if (next_process->type == TYPE_PROCESS_DUMMY)
	{
		if (next_process->list != NULL)
			return (lmt_process_next(next_process->list));
		else
			return (NULL);
	}
	else if (next_process->type == TYPE_PROCESS_NORMAL)
		return (next_process);
	else if (next_process->type == TYPE_PROCESS_PARENTHESIS)
		return (lmt_process_next(next_process->list));
	else
		return (NULL);
}

//	정상적으로 fork 된 자식 프로세스를 기다리는 함수
void	lmt_process_list_wait(t_lmt_process *dummy)
{
	t_lmt_process	*element;

	element = dummy->next;
	while (element != NULL)
	{
		lmt_process_wait(element);
		element = lmt_process_next(element);
	}
}
