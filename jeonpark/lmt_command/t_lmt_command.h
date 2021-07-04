/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:02:43 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:50:06 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_COMMAND_H
# define T_LMT_COMMAND_H

# include "lmt_env_path_array.h"

typedef struct s_lmt_command
{
	char	**argv;
	t_lmt_redirection	*redirection_array;
	pid_t	pid;
	struct s_lmt_command	*next;
}	t_lmt_command;

//	type function
t_lmt_command	*lmt_command_new(t_token *p_token);
void			lmt_command_free(t_lmt_command *p_command);

#endif
