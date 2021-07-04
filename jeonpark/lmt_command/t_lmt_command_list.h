/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_command_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 11:59:38 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 15:49:58 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_COMMAND_LIST_H
# define T_LMT_COMMAND_LIST_H

//	type function
t_lmt_command_list	*lmt_command_list_new();
void	lmt_command_list_free(t_lmt_command_list *p_lmt_command_list);

//	method function
void	lmt_command_list_push(t_lmt_command *p_list, t_token *p_token);

#endif
