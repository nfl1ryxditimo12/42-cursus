/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:39 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 19:32:57 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lmt_process.h"
#include "lmt_util.h"

static t_lmt_process	*lmt_process_alloc(void)
{
	return (lmt_alloc(sizeof(t_lmt_process)));
}

static void	lmt_process_init(t_lmt_process *p_process, char **argv, t_lmt_redirection **redirection_array)
{
	p_process->argv = argv;
	p_process->redirection_array = redirection_array;
}

t_lmt_process	*lmt_process_new(char **argv, t_lmt_redirection **redirection_array)
{
	t_lmt_process	*p_process;

	p_process = lmt_process_alloc();
	lmt_process_init(p_process, argv, redirection_array);
	return (p_process);
}

void	lmt_process_free(t_lmt_process *p_process)
{
	free(argv);
	lmt_redirection_array_free(p_process->redirection_array);
	free(p_process);
}
