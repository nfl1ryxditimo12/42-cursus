/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:58:18 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/07 21:52:38 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_UTIL_H
# define LMT_UTIL_H

# include <stddef.h>
# include "lmt_constant.h"
# include "lmt_string_array.h"

void	lmt_exit(int exit_code, char *string);
int	lmt_return_error(char *string);
void	*lmt_alloc(size_t size);
size_t	lmt_unsafe_strlen(const char *p_string);
int	lmt_get_exit_code_from_stat_loc(int stat_loc);

#endif
