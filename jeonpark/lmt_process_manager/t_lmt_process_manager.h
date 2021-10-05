/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/05 12:25:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_MANAGER_H
# define T_LMT_PROCESS_MANAGER_H

# include "lmt_process_manager_typedef.h"
#include "t_lmt_process.h"
#include "t_lmt_process_list.h"
#include "t_lmt_process_manager.h"
#include "t_lmt_redirection.h"
#include "t_lmt_redirection_list.h"
#include "lmt_tokenize.h"
#include "t_lmt_token_sublist.h"
#include "lmt_alloc.h"
#include "minishell.h"
#include "constant.h"

//	method function
int	lmt_process_manager_execute_token_sublist(t_handler *p_handler, t_lmt_token_sublist *token_sublist);
void	lmt_process_manager_execute(t_handler *p_handler);

#endif
