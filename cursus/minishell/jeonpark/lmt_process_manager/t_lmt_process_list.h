/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:59:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/27 09:52:55 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_LIST_H
# define T_LMT_PROCESS_LIST_H

# include "lmt_process_manager_typedef.h"

//	type function
t_lmt_process	*lmt_process_list_new(void);
void			lmt_process_list_free(t_lmt_process *list);
t_lmt_process	*lmt_process_list_new_by_token_sublist(
					t_lmt_token_sublist *token_sublist);

//	method function
void			lmt_process_list_append(
					t_lmt_process *list, t_lmt_process *element);
t_lmt_process	*lmt_process_dummy(t_lmt_process *process);
t_lmt_process	*lmt_process_prev(t_lmt_process *process);
t_lmt_process	*lmt_process_next(t_lmt_process *process);
void			lmt_process_list_wait(t_lmt_process *dummy);
void			lmt_process_list_set_by_token_sublist(
					t_lmt_process *list, t_lmt_token_sublist *token_sublist);
void			lmt_process_list_execute(
					t_lmt_process *dummy, t_lmt_process_manager *manager);

#endif
