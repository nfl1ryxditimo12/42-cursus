/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:49 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/05 16:44:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "lmt_constant.h"

int	signal_variable;

typedef void	(*t_signal_handler)(int);

static void	signal_set(int signal_number, t_signal_handler handler)
{
	if (signal(signal_number, handler) == SIG_ERR)
		exit(1);
}

static void	signal_handler_sigint(int signal)
{
	(void)signal;
	signal_variable = TRUE;
}

void	signal_init(void)
{
	signal_set(SIGINT, signal_handler_sigint);
	signal_set(SIGQUIT, SIG_IGN);
}
