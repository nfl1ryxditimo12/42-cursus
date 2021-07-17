/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/17 21:01:17 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_LIST_H
# define T_LMT_REDIRECTION_LIST_H

# include "lmt_process_manager_typedef.h"

//	lmt_redirection 들을 list 로 담아 놓는 구조체
typedef struct s_lmt_redirection_list
{
	t_lmt_redirection	*p_dummy;
	t_lmt_redirection	*last;
}	t_lmt_redirection_list;

//	type function
t_lmt_redirection_list	*lmt_redirection_list_new();
void	lmt_redirection_list_free(t_lmt_redirection_list *list, int option);

//	method function
void	lmt_redirection_list_push(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection);
void	lmt_redirection_list_append(t_lmt_redirection_list *list, t_lmt_redirection *p_redirection);
void	lmt_redirection_list_apply(t_lmt_redirection_list *list);
t_lmt_redirection_list	*lmt_redirection_list_backup(t_lmt_redirection_list *list);
void	lmt_redirection_list_backdown(t_lmt_redirection_list *list);

#endif
