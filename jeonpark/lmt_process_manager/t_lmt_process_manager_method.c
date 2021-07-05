/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager_method.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 22:24:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process_manager.h"
#include "lmt_util.h"

static int	lmt_process_manager_read_token(t_lmt_process_manager *p_proman, t_token *p_token)
{
	t_token	*iterator;

	iterator = p_token;
	while (iterator != NULL)
	{
		if (**iterator_string == '|')
			return (SYNTAX_ERROR_PIPE);
		lmt_process_list_append(p_proman->process_list, iterator->token, lmt_redirection_array_new());
		iterator = iterator->next;
		//	iterator 의 끝이 NULL 인가 아니면 갯수만큼 돌려야하는가?
		if (iterator == NULL)
			return (NORMAL);
		iterator = iterator->next;
		if (iterator == NULL)
			return (SYNTAX_ERROR_PIPE);
	}
}

int	lmt_process_manager_execute(t_token *p_token, char **env)
{
	t_lmt_process_manager *p_proman;
	int	ret;

	p_proman = lmt_process_manager_new();
	ret = lmt_process_manager_read_token(p_token);
	if (ret != NULL)
		return (ret);
	lmt_process_list_execute(p_proman->process_list, env);
	lmt_process_manager_free(p_proman);
}
