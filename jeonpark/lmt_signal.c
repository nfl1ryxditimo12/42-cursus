/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:49 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/03 14:13:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "lmt.h"

static void	lmt_sigaction_set(int signal, t_sigaction_handler handler)
{
	if (signal(signal, handler) == SIG_ERR)
		// error_exit();
}

void	lmt_signal_init(void)
{
	lmt_sigaction_seet(SIGINT, /* '<C-C>' signal function */);
	lmt_sigaction_seet(SIGQUIT, /* '<C-\>' signal function */);
}
