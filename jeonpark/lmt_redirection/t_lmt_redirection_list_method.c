/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list_method.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/11 20:10:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// NULL
#include "t_lmt_redirection_list.h"

//	새로운 노드를 p_dummy(통상 말하는 'top' 의 앞에 있는 node) 바로 뒤에 추가하는 함수
void	lmt_redirection_list_push(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection)
{
	p_redirection->next = list->p_dummy->next;
	list->p_dummy->next = p_redirection;
	if (list->last == list->p_dummy)
		list->last = p_redirection;
}

//	새로운 노드를 last(push_swap 에서 bottom 급) 바로 뒤에 추가하는 함수
void	lmt_redirection_list_append(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection)
{
	list->last->next = p_redirection;
	p_redirection->next = NULL;
	list->last = p_redirection;
}

//	lmt_redirection_list 의 lmt_redirection 들을 적용시키는 함수
void	lmt_redirection_list_apply(t_lmt_redirection_list *list)
{
	t_lmt_redirection	*iterator;

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		lmt_redirection_apply(iterator);
		iterator = iterator->next;
	}
}

//	Applies parameter 'list' and returns a redirection list for undo
//	lmt_redirection_list 를 적용시키고 undo(마치 'command-z' 처럼 되돌리는 작업) 하기 위한
//	lmt_redirection_list 를 생성하여 반환하는 함수
t_lmt_redirection_list	*lmt_redirection_list_backup(t_lmt_redirection_list *list)
{
	t_lmt_redirection		*iterator;
	int						fd_new;
	t_lmt_redirection		*p_element;
	t_lmt_redirection_list	*ret_list;

	ret_list = lmt_redirection_list_new();
	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		fd_new = lmt_redirection_backup(iterator);
		p_element = lmt_redirection_new(iterator->fd_old, FD_NONE, fd_new, NULL);
		lmt_redirection_list_push(ret_list, p_element);
		iterator = iterator->next;
	}
	return (ret_list);
}

//	undo 를 위해 생성된 lmt_redirection_list 를 인자로 받아서
//	apply 후 free 를 하는 함수
void	lmt_redirection_list_backdown(t_lmt_redirection_list *list)
{
//	free 는 왜 하지? 생각을 더 해봐야겠다
	lmt_redirection_list_apply(list);
	lmt_redirection_list_free(list, REDIRECTION_FREE);
}

void	lmt_redirection_list_new_by_token()
{
}
