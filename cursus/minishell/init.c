/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:23:08 by seonkim           #+#    #+#             */
/*   Updated: 2021/10/30 20:19:56 by seonkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "t_lmt_process_manager.h"

void	process_init_util(t_handler *hand, char *line)
{
	if (!line)
	{
		hand->status = 1;
		printf("exit\n");
		hand->exit = 1;
	}
	else if (!*line || is_space(line))
		hand->status = 0;
}

void	process_print(int status, t_handler *hand, char *line)
{
	if (status == 1)
	{
		printf("\n\x1b[33m========\x1b[0m Parse \x1b[33m====");
		printf("================================\x1b[0m\n\n");
		signal_set_status(STATUS_PARSING);
		line_split(hand, line);
	}
	else if (status == 0)
	{
		printf("\n\x1b[33m==================================");
		printf("=================\x1b[0m\n\n");
	}
	else
	{
		printf("\n\x1b[31m==================================");
		printf("=================\x1b[0m\n\n");
	}
}

void	process_init(t_handler *hand)
{
	char	*line;

	while (hand->exit == 0)
	{
		signal_set_status(STATUS_READING);
		line = readline(prompt(hand));
		if (!line || !*line || is_space(line))
			process_init_util(hand, line);
		else
		{
			hand_init(hand);
			add_history(line);
			process_print(1, hand, line);
			process_print(0, hand, line);
			hand->line = hand->top;
			if (chk_token_valid(hand))
				lmt_process_manager_execute(hand);
			else
				printf("Token Error!!\n");
			process_print(2, hand, line);
			hand_reset(hand);
		}
		free(line);
	}
}
