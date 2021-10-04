/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:33:31 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/16 17:46:46 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_CHECK_TYPE_H
# define LMT_CHECK_TYPE_H

int	lmt_is_type_operator(int type);
int	lmt_is_type_redirection(int type);
int	lmt_is_builtin(char *string);

#endif
