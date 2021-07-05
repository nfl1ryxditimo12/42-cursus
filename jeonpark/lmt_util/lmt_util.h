/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/05 11:33:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UTIL_H
# define LMT_UTIL_H

# include <stddef.h>
# include "lmt_constant.h"

void	lmt_exit(int exit_code, char *string);
void	*lmt_alloc(size_t size);
size_t	lmt_unsafe_strlen(const char *p_string);

#endif
