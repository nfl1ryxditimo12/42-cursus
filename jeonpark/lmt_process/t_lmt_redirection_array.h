/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lmt_redirection_array.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:32:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/04 19:28:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LMT_REDIRECTION_ARRAY_H
# define T_LMT_REDIRECTION_ARRAY_H

//	type function
t_lmt_redirection	**lmt_redirection_array_new();
void	lmt_redirection_array_free(t_lmt_redirection **array);

#endif
