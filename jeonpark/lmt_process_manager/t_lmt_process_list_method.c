/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list_method.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:04:04 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/06 11:02:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_list.h"
#include "t_lmt_process.h"
#include "lmt_util.h"

void	lmt_process_list_append(t_lmt_process_list *list, char **argv, t_lmt_redirection **redirection_array)
{
	t_lmt_process *p_element;

	p_element = lmt_process_new(argv, redirection_array);
	list->last->next = p_element;
	p_element->next = NULL;
	list->last = p_element;
}

void	lmt_process_list_execute(t_lmt_process_list *list, char **env)
{
	t_lmt_process	*iterator;
	int	fd_pipe[2];

	iterator = list->p_dummy->next;
	while (iterator != NULL)
	{
		if (iterator->next != NULL)
		{
			if (pipe(fd_pipe) == -1)
				lmt_exit(0, NULL);
			lmt_process_set_redirection(iterator, OUT, fd_pipe[PIPE_WRITE], NULL);
			lmt_process_set_redirection(iterator->next, IN, fd_pipe[PIPE_READ], NULL);
		}
		lmt_process_execute(iterator, env);
		close(fd_pipe[PIPE_WRITE]);
		//	PIPE_READ 는 어떻게 close 할 지 결정하기
		iterator = iterator->next;
	}
}
