/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:43:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command.h"
#include "lmt_util.h"

static t_lmt_command	*lmt_command_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_command)));
}

static void	lmt_command_init(t_lmt_command *p_command, char **argv, t_lmt_redirection *redirection_array)
{
	p_command->argv = argv;
	p_command->redirection_array = redirection_array;
}

t_lmt_command	*lmt_command_new(char **argv, t_lmt_redirection *redirection_array)
{
	t_lmt_command	*p_command;

	p_command = lmt_command_alloc();
	lmt_command_init(p_command, argv, redirection_array);
	return (p_command);
}

void	lmt_command_free(t_lmt_command *p_command)
{
	lmt_redirection_free(p_command->redirection_array);
	free(p_command);
}
