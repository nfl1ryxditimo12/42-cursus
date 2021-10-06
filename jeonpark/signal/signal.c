/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:49 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 11:45:06 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "signal.h"
#include "lmt_c_library.h"

typedef void	(*t_signal_handler)(int);

static void	signal_set(int signal_number, t_signal_handler handler)
{
	if (signal(signal_number, handler) == SIG_ERR)
		exit(1);
}

static void	signal_handler_sigint(int signal)
{
	(void)signal;
	if (is_reading_line)
	{
		lmt_put_ch('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	signal_set_init(void)
{
	rl_catch_signals = 0;
}

static void	signal_set_reading(void)
{
	signal_set(SIGINT, signal_handler_sigint);
	signal_set(SIGQUIT, SIG_IGN);
}

static void	signal_set_parsing(void)
{
	signal_set(SIGINT, SIG_IGN);
}

static void	signal_set_child(void)
{
	signal_set(SIGINT, SIG_DFL);
	signal_set(SIGQUIT, SIG_DFL);
}

void	signal_set_status(int status)
{
	if (status == STATUS_INIT)
		signal_set_init();
	else if (status == STATUS_READING)
		signal_set_reading();
	else if (status == STATUS_PARSING)
		signal_set_parsing();
	else if (status == STATUS_CHILD)
		signal_set_child();
}
