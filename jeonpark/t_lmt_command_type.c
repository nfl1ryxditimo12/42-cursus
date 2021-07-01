/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/02 19:47:31 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_command.h"
#include "lmt_util.h"

static t_lmt_command	*lmt_command_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_command)));
}

static void	lmt_command_init(t_lmt_command *p_command)
{
	p_command
}

t_lmt_command	*lmt_command_new(t_token *p_token)
{
	t_lmt_command	*p_command;

	p_command = lmt_command_alloc();
	lmt_command_init(p_command);
	return (p_command);
}

void	lmt_command_free(t_lmt_command *p_command)
{
	// Compose free code here..
	free(p_command);
}
