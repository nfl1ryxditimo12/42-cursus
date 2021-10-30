/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/30 19:50:14 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"

static int	attach_io(t_token *redirection_token,
		t_lmt_process_manager *manager, t_lmt_redirection_word_line **word_line)
{
	int	return_value;

	if (redirection_token->type == TYPE_REDIRECTION_IN
		|| redirection_token->type == TYPE_REDIRECTION_WORD)
		lmt_process_manager_dup_std_fd(manager, FD_IN);
	else if (redirection_token->type == TYPE_REDIRECTION_OUT
		|| redirection_token->type == TYPE_REDIRECTION_APPEND)
		lmt_process_manager_dup_std_fd(manager, FD_OUT);
	else
		return (NORMAL);
	return_value = lmt_attach_redirection(redirection_token,
			word_line, manager->fd_std[FD_IN], manager->fd_std[FD_OUT]);
	return (return_value);
}

int	lmt_process_attach_io(t_lmt_process *process,
		t_lmt_process_manager *manager)
{
	t_token						*element;
	int							return_value;
	t_lmt_redirection_word_line	*word_line;
	int							last_redirection_type;

	word_line = NULL;
	last_redirection_type = TYPE_UNDEFINED;
	lmt_process_manager_attach_pipe(manager);
	element = process->token_sublist->first->next;
	while (element != process->token_sublist->terminator)
	{
		if (lmt_is_token_type_redirection(element))
		{
			last_redirection_type = element->type;
			return_value = attach_io(element, manager, &word_line);
			if (return_value != NORMAL)
			{
				lmt_redirection_word_line_free(word_line);
				return (return_value);
			}
		}
		element = element->next;
	}
	if (last_redirection_type == TYPE_REDIRECTION_WORD)
		lmt_redirection_word_line_attach(word_line);
	lmt_redirection_word_line_free(word_line);
	return (NORMAL);
}
