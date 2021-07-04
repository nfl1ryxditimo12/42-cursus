/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:59:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 22:23:51 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_LIST_H
# define T_LMT_PROCESS_LIST_H

typedef struct s_lmt_process_list
{
	t_lmt_process	*p_dummy;
	t_lmt_process	*p_bottom;
}	t_lmt_process_list;

//	type function
t_lmt_process_list	*lmt_process_list_new();
void	lmt_process_list_free(t_lmt_process_list *p_process_list);

//	method function
void	lmt_process_list_append(t_lmt_process_list *list, char **argv, t_lmt_redirection **redirection_array);
void	lmt_process_list_execute(t_lmt_process_list *list, char **env);

#endif
