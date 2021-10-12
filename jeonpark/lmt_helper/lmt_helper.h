/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:14:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/12 10:46:13 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_HELPER_H
# define LMT_HELPER_H

int	lmt_count_of_null_terminated_array(void *array);

int	is_type_control_operator(int type);
int	is_type_redirection(int type);
int	is_type_open_parenthesis(int type);
int	is_type_close_parenthesis(int type);
int	is_type_command(int type);

int	lmt_get_exit_code_from_stat_loc(int stat_loc);

#endif
