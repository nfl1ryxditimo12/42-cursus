/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:49 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 11:09:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "lmt_util.h"

typedef void	(*t_signal_handler)(int);

static void	lmt_signal_set(int signal_number, t_signal_handler handler)
{
	if (signal(signal_number, handler) == SIG_ERR)
		lmt_exit(0 /* set_signal_error_exit_code */, NULL /* set error_massage */);
}

static void	signal_handler_sigint(int signal)
{
	(void)signal;
	/* '<C-C>' signal function */
}

static void	signal_handler_sigquit(int signal)
{
	(void)signal;
	/* '<C-\>' signal function */
}

void	lmt_signal_init(void)
{
	lmt_signal_set(SIGINT, signal_handler_sigint);
	lmt_signal_set(SIGQUIT, signal_handler_sigquit);
}
