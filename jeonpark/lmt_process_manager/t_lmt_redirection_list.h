/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_list.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 12:18:06 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_LIST_H
# define T_LMT_REDIRECTION_LIST_H

# include "lmt_process_manager_typedef.h"

typedef struct s_lmt_redirection_list
{
	t_lmt_redirection	*p_dummy;
	t_lmt_redirection	*last;
}	t_lmt_redirection_list;

//	type function
t_lmt_redirection_list	*lmt_redirection_list_new();
void	lmt_redirection_list_free(t_lmt_redirection_list *list, int option);

//	method function
void	lmt_redirection_list_append(t_lmt_redirection_list *list, int fd, char *path, int fd2);
void	lmt_redirection_list_apply(t_lmt_redirection_list *list);

#endif
