/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/03 20:39:14 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_COMMAND_H
# define T_LMT_COMMAND_H

# include "lmt_env_path_array.h"

# define IN		0
# define OUT	1
# define ERR	2

typedef struct s_lmt_command
{
	char	**argv;
	pid_t	pid;
	int	std_fd[3];
	struct s_lmt_command	*next;
}	t_lmt_command;

t_lmt_command	*lmt_command_new();
void			lmt_command_free(t_lmt_command *p_command);

#endif
