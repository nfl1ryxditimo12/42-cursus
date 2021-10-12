/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 20:45:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_MANAGER_H
# define T_LMT_PROCESS_MANAGER_H

# include "lmt_process_manager_typedef.h"
#include "t_lmt_process.h"
#include "t_lmt_process_list.h"
#include "t_lmt_process_manager.h"
#include "lmt_apply_redirection.h"
#include "t_lmt_token_sublist.h"
#include "lmt_c_library.h"
#include "minishell.h"
#include "constant.h"
#include "lmt_check_syntax_error.h"
#include "lmt_extension_token.h"

//	method function
int	lmt_process_manager_execute_token_sublist(t_handler *handler, t_lmt_token_sublist *token_sublist, int pipe_in_fd);
int	lmt_process_manager_execute(t_handler *handler);

#endif
