/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:49 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 05:58:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
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
	lmt_put_ch('\n');
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_init(void)
{
	signal_set(SIGINT, signal_handler_sigint);
	signal_set(SIGQUIT, SIG_IGN);
}
