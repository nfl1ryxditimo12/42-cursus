/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/08 19:41:12 by jeonpark         ###   ########.fr       */
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
#include "t_lmt_token.h"
#include "t_lmt_token_list.h"
#include "t_lmt_token_sublist.h"
#include "lmt_util.h"
#include "minishell.h"

typedef struct s_lmt_process_manager
{
	t_lmt_token_list	*token_list;
	t_lmt_token_sublist	*token_sublist;
}	t_lmt_process_manager;

//	type function
t_lmt_process_manager	*lmt_process_manager_new(t_lmt_token_list *token_list);
void	lmt_process_manager_free(t_lmt_process_manager *p_proman);

//	method function
int	lmt_process_manager_execute(t_lmt_token_sublist *token_sublist, char **env);
int	lmt_process_manager_execute_by_handler(t_handler *hand, char **env);

#endif
