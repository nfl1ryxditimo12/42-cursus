/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:36:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 11:06:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_H
# define T_LMT_REDIRECTION_H

#include "t_lmt_process_manager.h"
#include "minishell.h"	// t_token
#include "lmt_c_library.h"
#include "constant.h"

void	lmt_apply_pipe_redirection(t_lmt_process *process);
int		lmt_apply_redirection(t_token *token, int should_backup);

#endif
