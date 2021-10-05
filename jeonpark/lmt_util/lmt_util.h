/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/06 05:59:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UTIL_H
# define LMT_UTIL_H

int	is_type_operator(int type);
int	is_type_redirection(int type);

int	lmt_get_exit_code_from_stat_loc(int stat_loc);

#endif
