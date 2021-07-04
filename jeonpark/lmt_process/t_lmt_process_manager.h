/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_process_manager.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:18:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 18:43:33 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_PROCESS_MANAGER_H
# define T_LMT_PROCESS_MANAGER_H

typedef struct s_lmt_process_manager
{
	t_lmt_token_list	*token_list;
	t_lmt_process_list	*process_list;
}	t_lmt_process_manager;

t_lmt_process_manager	*lmt_process_manager_new(void);
void	*lmt_process_manager_free(t_lmt_process_manager *p_proman);

#endif
