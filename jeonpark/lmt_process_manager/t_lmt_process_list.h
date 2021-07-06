/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:59:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 20:06:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_LIST_H
# define T_LMT_PROCESS_LIST_H

# include "lmt_process_manager_typedef.h"

typedef struct s_lmt_process_list
{
	t_lmt_process	*p_dummy;
	t_lmt_process	*last;
	t_lmt_redirection_list	*redirection_to_close_list;
}	t_lmt_process_list;

//	type function
t_lmt_process_list	*lmt_process_list_new();
void	lmt_process_list_free(t_lmt_process_list *list);

//	method function
void	lmt_process_list_append(t_lmt_process_list *list, t_lmt_process *p_process);
int	lmt_process_list_execute(t_lmt_process_list *list, char **env);

#endif
