/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 20:17:44 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_MANAGER_H
# define T_LMT_PROCESS_MANAGER_H

# include "lmt_process_manager_typedef.h"

//	close 할 redirection 을 list 에 보관했다가 close 하는데, fd 한계가 발생할 수 있으므로 생각을 더 해볼 것
typedef struct s_lmt_process_manager
{
	t_lmt_token_list	*token_list;
	t_lmt_token_sublist	*token_sublist;
	t_lmt_process_list	*process_list;
}	t_lmt_process_manager;

//	type function
t_lmt_process_manager	*lmt_process_manager_new(void);
void	lmt_process_manager_free(t_lmt_process_manager *p_proman);

//	method function
int	lmt_process_manager_execute(t_token *p_token, char **env);

#endif
